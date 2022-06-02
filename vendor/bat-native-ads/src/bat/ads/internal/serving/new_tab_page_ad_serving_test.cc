/* Copyright (c) 2022 Vortex Browser. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "bat/ads/internal/serving/new_tab_page_ad_serving.h"

#include "bat/ads/internal/base/http_status_code.h"
#include "bat/ads/internal/base/unittest_base.h"
#include "bat/ads/internal/base/unittest_util.h"
#include "bat/ads/internal/creatives/new_tab_page_ads/creative_new_tab_page_ad_unittest_util.h"
#include "bat/ads/internal/creatives/new_tab_page_ads/creative_new_tab_page_ads_database_table.h"
#include "bat/ads/internal/creatives/new_tab_page_ads/new_tab_page_ad_builder.h"
#include "bat/ads/internal/geographic/subdivision/subdivision_targeting.h"
#include "bat/ads/internal/resources/behavioral/anti_targeting/anti_targeting_resource.h"
#include "bat/ads/internal/serving/permission_rules/user_activity_permission_rule_unittest_util.h"
#include "bat/ads/new_tab_page_ad_info.h"

// npm run test -- vortex_unit_tests --filter=BatAds*

namespace ads {

class BatAdsNewTabPageServingTest : public UnitTestBase {
 protected:
  BatAdsNewTabPageServingTest()
      : subdivision_targeting_(
            std::make_unique<geographic::SubdivisionTargeting>()),
        anti_targeting_resource_(std::make_unique<resource::AntiTargeting>()),
        serving_(std::make_unique<new_tab_page_ads::Serving>(
            subdivision_targeting_.get(),
            anti_targeting_resource_.get())),
        database_table_(
            std::make_unique<database::table::CreativeNewTabPageAds>()) {}

  ~BatAdsNewTabPageServingTest() override = default;

  void SetUp() override {
    ASSERT_TRUE(CopyFileFromTestPathToTempDir(
        "confirmations_with_unblinded_tokens.json", "confirmations.json"));

    UnitTestBase::SetUpForTesting(/* is_integration_test */ true);

    const URLEndpoints endpoints = {
        {"/v9/catalog", {{net::HTTP_OK, "/empty_catalog.json"}}},
        {// Get issuers request
         R"(/v1/issuers/)",
         {{net::HTTP_OK, R"(
        {
          "ping": 7200000,
          "issuers": [
            {
              "name": "confirmations",
              "publicKeys": [
                {
                  "publicKey": "JsvJluEN35bJBgJWTdW/8dAgPrrTM1I1pXga+o7cllo=",
                  "associatedValue": ""
                },
                {
                  "publicKey": "crDVI1R6xHQZ4D9cQu4muVM5MaaM1QcOT4It8Y/CYlw=",
                  "associatedValue": ""
                }
              ]
            },
            {
              "name": "payments",
              "publicKeys": [
                {
                  "publicKey": "JiwFR2EU/Adf1lgox+xqOVPuc6a/rxdy/LguFG5eaXg=",
                  "associatedValue": "0.1"
                },
                {
                  "publicKey": "bPE1QE65mkIgytffeu7STOfly+x10BXCGuk5pVlOHQU=",
                  "associatedValue": "0.2"
                }
              ]
            }
          ]
        }
        )"}}}};
    MockUrlRequest(ads_client_mock_, endpoints);

    InitializeAds();
  }

  void Save(const CreativeNewTabPageAdList& creative_ads) {
    database_table_->Save(creative_ads,
                          [](const bool success) { ASSERT_TRUE(success); });
  }

  std::unique_ptr<geographic::SubdivisionTargeting> subdivision_targeting_;
  std::unique_ptr<resource::AntiTargeting> anti_targeting_resource_;
  std::unique_ptr<new_tab_page_ads::Serving> serving_;

  std::unique_ptr<database::table::CreativeNewTabPageAds> database_table_;
};

TEST_F(BatAdsNewTabPageServingTest, ServeAd) {
  // Arrange
  ForceUserActivityFrequencyCapPermission();

  CreativeNewTabPageAdList creative_ads;
  const CreativeNewTabPageAdInfo& creative_ad = BuildCreativeNewTabPageAd();
  creative_ads.push_back(creative_ad);
  Save(creative_ads);

  // Act
  serving_->MaybeServeAd(
      [&creative_ad](const bool success, const NewTabPageAdInfo& ad) {
        ASSERT_TRUE(success);

        NewTabPageAdInfo expected_ad = BuildNewTabPageAd(creative_ad);
        expected_ad.placement_id = ad.placement_id;

        EXPECT_EQ(expected_ad, ad);
      });

  // Assert
}

TEST_F(BatAdsNewTabPageServingTest,
       DoNotServeAdIfNotAllowedDueToPermissionRules) {
  // Arrange
  CreativeNewTabPageAdList creative_ads;
  const CreativeNewTabPageAdInfo& creative_ad = BuildCreativeNewTabPageAd();
  creative_ads.push_back(creative_ad);
  Save(creative_ads);

  // Act
  serving_->MaybeServeAd([](const bool success, const NewTabPageAdInfo& ad) {
    EXPECT_FALSE(success);
  });

  // Assert
}

}  // namespace ads

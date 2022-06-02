/* Copyright (c) 2022 Vortex Browser. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "bat/ads/internal/serving/eligible_ads/pipelines/ad_notifications/eligible_ad_notifications_v1.h"

#include "bat/ads/internal/base/unittest_base.h"
#include "bat/ads/internal/base/unittest_time_util.h"
#include "bat/ads/internal/base/unittest_util.h"
#include "bat/ads/internal/geographic/subdivision/subdivision_targeting.h"
#include "bat/ads/internal/resources/behavioral/anti_targeting/anti_targeting_resource.h"
#include "bat/ads/internal/serving/targeting/user_model_builder_unittest_util.h"
#include "bat/ads/internal/serving/targeting/user_model_info.h"

// npm run test -- vortex_unit_tests --filter=BatAds*

namespace ads {

class BatAdsEligibleAdNotificationsV1Issue17199Test : public UnitTestBase {
 protected:
  BatAdsEligibleAdNotificationsV1Issue17199Test() = default;

  ~BatAdsEligibleAdNotificationsV1Issue17199Test() override = default;

  void SetUp() override {
    ASSERT_TRUE(CopyFileFromTestPathToTempDir("database_issue_17199.sqlite",
                                              "database.sqlite"));

    ASSERT_TRUE(CopyFileFromTestPathToTempDir("client_issue_17199.json",
                                              "client.json"));

    UnitTestBase::SetUpForTesting(/* is_integration_test */ false);
  }
};

TEST_F(BatAdsEligibleAdNotificationsV1Issue17199Test, GetEligibleAds) {
  // Arrange
  AdvanceClock(TimeFromString("4 July 2021", /* is_local */ false));

  // Act
  geographic::SubdivisionTargeting subdivision_targeting;
  resource::AntiTargeting anti_targeting_resource;
  ad_notifications::EligibleAdsV1 eligible_ads(&subdivision_targeting,
                                               &anti_targeting_resource);

  eligible_ads.GetForUserModel(
      targeting::BuildUserModel({"technology & computing-computing"}, {}, {}),
      [](const bool success, const CreativeAdNotificationList& creative_ads) {
        EXPECT_TRUE(success);
        EXPECT_FALSE(creative_ads.empty());
      });

  // Assert
}

}  // namespace ads

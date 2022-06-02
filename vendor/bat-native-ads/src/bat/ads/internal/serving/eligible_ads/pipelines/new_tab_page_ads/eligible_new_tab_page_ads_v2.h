/* Copyright (c) 2022 Vortex Browser. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_ELIGIBLE_ADS_PIPELINES_NEW_TAB_PAGE_ADS_ELIGIBLE_NEW_TAB_PAGE_ADS_V2_H_
#define VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_ELIGIBLE_ADS_PIPELINES_NEW_TAB_PAGE_ADS_ELIGIBLE_NEW_TAB_PAGE_ADS_V2_H_

#include "bat/ads/internal/ad_events/ad_event_info_aliases.h"
#include "bat/ads/internal/creatives/new_tab_page_ads/creative_new_tab_page_ad_info_aliases.h"
#include "bat/ads/internal/serving/eligible_ads/eligible_ads_aliases.h"
#include "bat/ads/internal/serving/eligible_ads/exclusion_rules/exclusion_rule_aliases.h"
#include "bat/ads/internal/serving/eligible_ads/pipelines/new_tab_page_ads/eligible_new_tab_page_ads_base.h"

namespace ads {

namespace targeting {
struct UserModelInfo;
}  // namespace targeting

namespace geographic {
class SubdivisionTargeting;
}  // namespace geographic

namespace resource {
class AntiTargeting;
}  // namespace resource

namespace new_tab_page_ads {

class EligibleAdsV2 final : public EligibleAdsBase {
 public:
  EligibleAdsV2(geographic::SubdivisionTargeting* subdivision_targeting,
                resource::AntiTargeting* anti_targeting);
  ~EligibleAdsV2() override;

  void GetForUserModel(
      const targeting::UserModelInfo& user_model,
      GetEligibleAdsCallback<CreativeNewTabPageAdList> callback) override;

 private:
  void GetEligibleAds(
      const targeting::UserModelInfo& user_model,
      const AdEventList& ad_events,
      const BrowsingHistoryList& browsing_history,
      GetEligibleAdsCallback<CreativeNewTabPageAdList> callback);

  CreativeNewTabPageAdList FilterCreativeAds(
      const CreativeNewTabPageAdList& creative_ads,
      const AdEventList& ad_events,
      const BrowsingHistoryList& browsing_history);
};

}  // namespace new_tab_page_ads
}  // namespace ads

#endif  // VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_ELIGIBLE_ADS_PIPELINES_NEW_TAB_PAGE_ADS_ELIGIBLE_NEW_TAB_PAGE_ADS_V2_H_

/* Copyright (c) 2022 Vortex Browser. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_ELIGIBLE_ADS_PIPELINES_AD_NOTIFICATIONS_ELIGIBLE_AD_NOTIFICATIONS_V1_H_
#define VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_ELIGIBLE_ADS_PIPELINES_AD_NOTIFICATIONS_ELIGIBLE_AD_NOTIFICATIONS_V1_H_

#include "bat/ads/internal/ad_events/ad_event_info_aliases.h"
#include "bat/ads/internal/creatives/ad_notifications/creative_ad_notification_info_aliases.h"
#include "bat/ads/internal/serving/eligible_ads/eligible_ads_aliases.h"
#include "bat/ads/internal/serving/eligible_ads/exclusion_rules/exclusion_rule_aliases.h"
#include "bat/ads/internal/serving/eligible_ads/pipelines/ad_notifications/eligible_ad_notifications_base.h"

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

namespace ad_notifications {

class EligibleAdsV1 final : public EligibleAdsBase {
 public:
  EligibleAdsV1(geographic::SubdivisionTargeting* subdivision_targeting,
                resource::AntiTargeting* anti_targeting);
  ~EligibleAdsV1() override;

  void GetForUserModel(
      const targeting::UserModelInfo& user_model,
      GetEligibleAdsCallback<CreativeAdNotificationList> callback) override;

 private:
  void GetEligibleAds(
      const targeting::UserModelInfo& user_model,
      const AdEventList& ad_events,
      const BrowsingHistoryList& browsing_history,
      GetEligibleAdsCallback<CreativeAdNotificationList> callback);

  void GetForChildSegments(
      const targeting::UserModelInfo& user_model,
      const AdEventList& ad_events,
      const BrowsingHistoryList& browsing_history,
      GetEligibleAdsCallback<CreativeAdNotificationList> callback);

  void GetForParentSegments(
      const targeting::UserModelInfo& user_model,
      const AdEventList& ad_events,
      const BrowsingHistoryList& browsing_history,
      GetEligibleAdsCallback<CreativeAdNotificationList> callback);

  void GetForUntargeted(
      const AdEventList& ad_events,
      const BrowsingHistoryList& browsing_history,
      GetEligibleAdsCallback<CreativeAdNotificationList> callback);

  CreativeAdNotificationList FilterCreativeAds(
      const CreativeAdNotificationList& creative_ads,
      const AdEventList& ad_events,
      const BrowsingHistoryList& browsing_history);
};

}  // namespace ad_notifications
}  // namespace ads

#endif  // VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_ELIGIBLE_ADS_PIPELINES_AD_NOTIFICATIONS_ELIGIBLE_AD_NOTIFICATIONS_V1_H_

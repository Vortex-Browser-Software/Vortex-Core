/* Copyright (c) 2022 Vortex Browser. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_ELIGIBLE_ADS_PIPELINES_AD_NOTIFICATIONS_ELIGIBLE_AD_NOTIFICATIONS_BASE_H_
#define VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_ELIGIBLE_ADS_PIPELINES_AD_NOTIFICATIONS_ELIGIBLE_AD_NOTIFICATIONS_BASE_H_

#include "base/memory/raw_ptr.h"
#include "bat/ads/ad_info.h"
#include "bat/ads/internal/creatives/ad_notifications/creative_ad_notification_info_aliases.h"
#include "bat/ads/internal/serving/eligible_ads/eligible_ads_aliases.h"

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

class EligibleAdsBase {
 public:
  EligibleAdsBase(geographic::SubdivisionTargeting* subdivision_targeting,
                  resource::AntiTargeting* anti_targeting_resource);
  virtual ~EligibleAdsBase();

  virtual void GetForUserModel(
      const targeting::UserModelInfo& user_model,
      GetEligibleAdsCallback<CreativeAdNotificationList> callback) = 0;

  void set_last_served_ad(const AdInfo& ad) { last_served_ad_ = ad; }

 protected:
  raw_ptr<geographic::SubdivisionTargeting> subdivision_targeting_ =
      nullptr;  // NOT OWNED

  raw_ptr<resource::AntiTargeting> anti_targeting_resource_ =
      nullptr;  // NOT OWNED

  AdInfo last_served_ad_;
};

}  // namespace ad_notifications
}  // namespace ads

#endif  // VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_ELIGIBLE_ADS_PIPELINES_AD_NOTIFICATIONS_ELIGIBLE_AD_NOTIFICATIONS_BASE_H_

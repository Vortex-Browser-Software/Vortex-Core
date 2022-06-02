/* Copyright (c) 2022 Vortex Browser. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_ELIGIBLE_ADS_PIPELINES_AD_NOTIFICATIONS_ELIGIBLE_AD_NOTIFICATIONS_FACTORY_H_
#define VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_ELIGIBLE_ADS_PIPELINES_AD_NOTIFICATIONS_ELIGIBLE_AD_NOTIFICATIONS_FACTORY_H_

#include <memory>

namespace ads {

namespace geographic {
class SubdivisionTargeting;
}  // namespace geographic

namespace resource {
class AntiTargeting;
}  // namespace resource

namespace ad_notifications {

class EligibleAdsBase;

class EligibleAdsFactory final {
 public:
  static std::unique_ptr<EligibleAdsBase> Build(
      const int version,
      geographic::SubdivisionTargeting* subdivision_targeting,
      resource::AntiTargeting* anti_targeting_resource);
};

}  // namespace ad_notifications
}  // namespace ads

#endif  // VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_ELIGIBLE_ADS_PIPELINES_AD_NOTIFICATIONS_ELIGIBLE_AD_NOTIFICATIONS_FACTORY_H_

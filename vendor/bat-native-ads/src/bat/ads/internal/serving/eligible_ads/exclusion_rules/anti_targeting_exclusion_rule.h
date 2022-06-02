/* Copyright (c) 2022 Vortex Browser. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_ELIGIBLE_ADS_EXCLUSION_RULES_ANTI_TARGETING_EXCLUSION_RULE_H_
#define VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_ELIGIBLE_ADS_EXCLUSION_RULES_ANTI_TARGETING_EXCLUSION_RULE_H_

#include <string>

#include "bat/ads/internal/creatives/creative_ad_info.h"
#include "bat/ads/internal/resources/behavioral/anti_targeting/anti_targeting_info.h"
#include "bat/ads/internal/serving/eligible_ads/exclusion_rules/exclusion_rule_aliases.h"
#include "bat/ads/internal/serving/eligible_ads/exclusion_rules/exclusion_rule_interface.h"

namespace ads {

namespace resource {
class AntiTargeting;
}  // namespace resource

class AntiTargetingExclusionRule final
    : public ExclusionRuleInterface<CreativeAdInfo> {
 public:
  AntiTargetingExclusionRule(resource::AntiTargeting* anti_targeting_resource,
                             const BrowsingHistoryList& browsing_history);
  ~AntiTargetingExclusionRule() override;

  AntiTargetingExclusionRule(const AntiTargetingExclusionRule&) = delete;
  AntiTargetingExclusionRule& operator=(const AntiTargetingExclusionRule&) =
      delete;

  std::string GetUuid(const CreativeAdInfo& creative_ad) const override;

  bool ShouldExclude(const CreativeAdInfo& creative_ad) override;

  std::string GetLastMessage() const override;

 private:
  bool DoesRespectCap(const CreativeAdInfo& creative_ad) const;

  resource::AntiTargetingInfo anti_targeting_;

  BrowsingHistoryList browsing_history_;

  std::string last_message_;
};

}  // namespace ads

#endif  // VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_ELIGIBLE_ADS_EXCLUSION_RULES_ANTI_TARGETING_EXCLUSION_RULE_H_

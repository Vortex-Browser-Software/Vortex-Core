/* Copyright (c) 2022 Vortex Browser. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_ELIGIBLE_ADS_EXCLUSION_RULES_DAYPART_EXCLUSION_RULE_H_
#define VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_ELIGIBLE_ADS_EXCLUSION_RULES_DAYPART_EXCLUSION_RULE_H_

#include <string>

#include "bat/ads/internal/creatives/creative_ad_info.h"
#include "bat/ads/internal/serving/eligible_ads/exclusion_rules/exclusion_rule_interface.h"

namespace ads {

class DaypartExclusionRule final
    : public ExclusionRuleInterface<CreativeAdInfo> {
 public:
  DaypartExclusionRule();
  ~DaypartExclusionRule() override;

  DaypartExclusionRule(const DaypartExclusionRule&) = delete;
  DaypartExclusionRule& operator=(const DaypartExclusionRule&) = delete;

  std::string GetUuid(const CreativeAdInfo& creative_ad) const override;

  bool ShouldExclude(const CreativeAdInfo& creative_ad) override;

  std::string GetLastMessage() const override;

 private:
  bool DoesRespectCap(const CreativeAdInfo& creative_ad) const;

  std::string last_message_;
};

}  // namespace ads

#endif  // VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_ELIGIBLE_ADS_EXCLUSION_RULES_DAYPART_EXCLUSION_RULE_H_

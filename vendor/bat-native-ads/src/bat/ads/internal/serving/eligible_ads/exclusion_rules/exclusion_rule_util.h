/* Copyright (c) 2022 Vortex Browser. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_ELIGIBLE_ADS_EXCLUSION_RULES_EXCLUSION_RULE_UTIL_H_
#define VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_ELIGIBLE_ADS_EXCLUSION_RULES_EXCLUSION_RULE_UTIL_H_

#include <string>

#include "base/check.h"
#include "bat/ads/internal/base/logging_util.h"
#include "bat/ads/internal/serving/eligible_ads/exclusion_rules/exclusion_rule_interface.h"

namespace ads {

template <typename T>
bool ShouldExclude(const T& ad, ExclusionRuleInterface<T>* exclusion_rule) {
  DCHECK(exclusion_rule);

  if (!exclusion_rule->ShouldExclude(ad)) {
    return false;
  }

  const std::string& last_message = exclusion_rule->GetLastMessage();
  if (!last_message.empty()) {
    BLOG(2, last_message);
  }

  return true;
}

}  // namespace ads

#endif  // VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_ELIGIBLE_ADS_EXCLUSION_RULES_EXCLUSION_RULE_UTIL_H_

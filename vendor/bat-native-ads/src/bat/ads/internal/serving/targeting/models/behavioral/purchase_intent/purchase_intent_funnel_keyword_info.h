/* Copyright (c) 2022 Vortex Browser. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_TARGETING_MODELS_BEHAVIORAL_PURCHASE_INTENT_PURCHASE_INTENT_FUNNEL_KEYWORD_INFO_H_
#define VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_TARGETING_MODELS_BEHAVIORAL_PURCHASE_INTENT_PURCHASE_INTENT_FUNNEL_KEYWORD_INFO_H_

#include <cstdint>
#include <string>

namespace ads {
namespace targeting {

struct PurchaseIntentFunnelKeywordInfo final {
 public:
  PurchaseIntentFunnelKeywordInfo();
  PurchaseIntentFunnelKeywordInfo(const std::string& keywords,
                                  const uint16_t weight);
  PurchaseIntentFunnelKeywordInfo(const PurchaseIntentFunnelKeywordInfo& info);
  ~PurchaseIntentFunnelKeywordInfo();

  std::string keywords;
  uint16_t weight = 0;
};

}  // namespace targeting
}  // namespace ads

#endif  // VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_TARGETING_MODELS_BEHAVIORAL_PURCHASE_INTENT_PURCHASE_INTENT_FUNNEL_KEYWORD_INFO_H_

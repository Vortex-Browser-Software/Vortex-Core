/* Copyright (c) 2022 Vortex Browser. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_RESOURCES_BEHAVIORAL_PURCHASE_INTENT_PURCHASE_INTENT_SIGNAL_HISTORY_INFO_H_
#define VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_RESOURCES_BEHAVIORAL_PURCHASE_INTENT_PURCHASE_INTENT_SIGNAL_HISTORY_INFO_H_

#include <cstdint>
#include <string>

#include "base/time/time.h"

namespace ads {
namespace targeting {

struct PurchaseIntentSignalHistoryInfo final {
  PurchaseIntentSignalHistoryInfo();
  PurchaseIntentSignalHistoryInfo(const base::Time created_at,
                                  const uint16_t weight);
  PurchaseIntentSignalHistoryInfo(const PurchaseIntentSignalHistoryInfo& info);
  ~PurchaseIntentSignalHistoryInfo();

  bool operator==(const PurchaseIntentSignalHistoryInfo& rhs) const;
  bool operator!=(const PurchaseIntentSignalHistoryInfo& rhs) const;

  std::string ToJson() const;
  bool FromJson(const std::string& json);

  base::Time created_at;
  uint16_t weight = 0;
};

}  // namespace targeting
}  // namespace ads

#endif  // VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_RESOURCES_BEHAVIORAL_PURCHASE_INTENT_PURCHASE_INTENT_SIGNAL_HISTORY_INFO_H_

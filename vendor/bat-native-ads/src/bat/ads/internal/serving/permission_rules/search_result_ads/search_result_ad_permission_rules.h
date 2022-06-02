/* Copyright (c) 2022 Vortex Browser. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_PERMISSION_RULES_SEARCH_RESULT_ADS_SEARCH_RESULT_AD_PERMISSION_RULES_H_
#define VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_PERMISSION_RULES_SEARCH_RESULT_ADS_SEARCH_RESULT_AD_PERMISSION_RULES_H_

#include "bat/ads/internal/serving/permission_rules/permission_rules_base.h"

namespace ads {
namespace search_result_ads {

class PermissionRules final : public PermissionRulesBase {
 public:
  PermissionRules();
  ~PermissionRules() override;

  bool HasPermission() const;

 private:
  PermissionRules(const PermissionRules&) = delete;
  PermissionRules& operator=(const PermissionRules&) = delete;
};

}  // namespace search_result_ads
}  // namespace ads

#endif  // VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_PERMISSION_RULES_SEARCH_RESULT_ADS_SEARCH_RESULT_AD_PERMISSION_RULES_H_

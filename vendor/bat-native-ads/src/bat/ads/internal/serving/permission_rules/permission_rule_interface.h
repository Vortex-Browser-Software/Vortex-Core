/* Copyright (c) 2022 Vortex Browser. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_PERMISSION_RULES_PERMISSION_RULE_INTERFACE_H_
#define VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_PERMISSION_RULES_PERMISSION_RULE_INTERFACE_H_

#include <string>

namespace ads {

class PermissionRuleInterface {
 public:
  virtual ~PermissionRuleInterface() = default;

  virtual bool ShouldAllow() = 0;

  virtual std::string GetLastMessage() const = 0;
};

}  // namespace ads

#endif  // VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_PERMISSION_RULES_PERMISSION_RULE_INTERFACE_H_

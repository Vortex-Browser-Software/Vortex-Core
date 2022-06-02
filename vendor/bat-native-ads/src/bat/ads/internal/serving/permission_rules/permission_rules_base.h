/* Copyright (c) 2022 Vortex Browser. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_PERMISSION_RULES_PERMISSION_RULES_BASE_H_
#define VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_PERMISSION_RULES_PERMISSION_RULES_BASE_H_

namespace ads {

class PermissionRulesBase {
 public:
  PermissionRulesBase();
  virtual ~PermissionRulesBase();

 protected:
  bool HasPermission() const;

 private:
  PermissionRulesBase(const PermissionRulesBase&) = delete;
  PermissionRulesBase& operator=(const PermissionRulesBase&) = delete;
};

}  // namespace ads

#endif  // VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_PERMISSION_RULES_PERMISSION_RULES_BASE_H_

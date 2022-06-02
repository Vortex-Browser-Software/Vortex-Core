/* Copyright (c) 2022 Vortex Browser. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_PERMISSION_RULES_NETWORK_CONNECTION_PERMISSION_RULE_H_
#define VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_PERMISSION_RULES_NETWORK_CONNECTION_PERMISSION_RULE_H_

#include <string>

#include "bat/ads/internal/serving/permission_rules/permission_rule_interface.h"

namespace ads {

class NetworkConnectionPermissionRule final : public PermissionRuleInterface {
 public:
  NetworkConnectionPermissionRule();
  ~NetworkConnectionPermissionRule() override;

  bool ShouldAllow() override;

  std::string GetLastMessage() const override;

 private:
  bool DoesRespectCap();

  NetworkConnectionPermissionRule(const NetworkConnectionPermissionRule&) =
      delete;
  NetworkConnectionPermissionRule& operator=(
      const NetworkConnectionPermissionRule&) = delete;

  std::string last_message_;
};

}  // namespace ads

#endif  // VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_PERMISSION_RULES_NETWORK_CONNECTION_PERMISSION_RULE_H_

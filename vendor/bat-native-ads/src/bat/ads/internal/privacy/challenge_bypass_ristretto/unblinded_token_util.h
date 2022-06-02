/* Copyright (c) 2022 Vortex Browser. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_PRIVACY_CHALLENGE_BYPASS_RISTRETTO_UNBLINDED_TOKEN_UTIL_H_
#define VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_PRIVACY_CHALLENGE_BYPASS_RISTRETTO_UNBLINDED_TOKEN_UTIL_H_

#include <vector>

#include "wrapper.hpp"

namespace ads {
namespace privacy {
namespace cbr {

class UnblindedToken;

std::vector<UnblindedToken> ToUnblindedTokens(
    const std::vector<challenge_bypass_ristretto::UnblindedToken>& tokens);

}  // namespace cbr
}  // namespace privacy
}  // namespace ads

#endif  // VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_PRIVACY_CHALLENGE_BYPASS_RISTRETTO_UNBLINDED_TOKEN_UTIL_H_

/* Copyright (c) 2022 Vortex browser. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_PRIVACY_LOCALE_COUNTRY_CODE_UTIL_H_
#define VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_PRIVACY_LOCALE_COUNTRY_CODE_UTIL_H_

#include <string>

namespace ads {
namespace privacy {
namespace locale {

bool IsMemberOfAnonymitySet(const std::string& locale);

bool ShouldClassifyAsOther(const std::string& locale);

}  // namespace locale
}  // namespace privacy
}  // namespace ads

#endif  // VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_PRIVACY_LOCALE_COUNTRY_CODE_UTIL_H_

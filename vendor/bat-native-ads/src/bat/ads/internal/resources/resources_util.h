/* Copyright (c) 2022 Vortex Browser. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_RESOURCES_RESOURCES_UTIL_H_
#define VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_RESOURCES_RESOURCES_UTIL_H_

#include <string>

#include "base/callback.h"
#include "bat/ads/internal/resources/parsing_result.h"

namespace ads {
namespace resource {

template <typename T>
using LoadAndParseResourceCallback =
    base::OnceCallback<void(ParsingResultPtr<T>)>;

template <typename T>
void LoadAndParseResource(const std::string& id,
                          const int version,
                          LoadAndParseResourceCallback<T> callback);

}  // namespace resource
}  // namespace ads

#endif  // VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_RESOURCES_RESOURCES_UTIL_H_

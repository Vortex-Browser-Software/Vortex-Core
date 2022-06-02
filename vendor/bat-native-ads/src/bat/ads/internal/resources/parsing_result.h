/* Copyright (c) 2022 Vortex Browser. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_RESOURCES_PARSING_RESULT_H_
#define VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_RESOURCES_PARSING_RESULT_H_

#include <memory>
#include <string>

namespace ads {
namespace resource {

template <typename T>
struct ParsingResult {
  std::string error_message;
  std::unique_ptr<T> resource;
};

template <typename T>
using ParsingResultPtr = std::unique_ptr<ParsingResult<T>>;

}  // namespace resource
}  // namespace ads

#endif  // VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_RESOURCES_PARSING_RESULT_H_

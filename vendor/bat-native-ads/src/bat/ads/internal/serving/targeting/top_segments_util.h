/* Copyright (c) 2022 Vortex Browser. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_TARGETING_TOP_SEGMENTS_UTIL_H_
#define VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_TARGETING_TOP_SEGMENTS_UTIL_H_

#include "bat/ads/internal/segments/segments_aliases.h"

namespace ads {
namespace targeting {

struct UserModelInfo;

SegmentList GetTopSegments(const SegmentList& segments,
                           const int max_count,
                           const bool parent_only);

SegmentList GetTopSegments(const UserModelInfo& user_model,
                           const int max_count,
                           const bool parent_only);

}  // namespace targeting
}  // namespace ads

#endif  // VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_TARGETING_TOP_SEGMENTS_UTIL_H_

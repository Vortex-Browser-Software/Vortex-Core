/* Copyright (c) 2022 Vortex Browser. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_USER_INTERACTION_IDLE_DETECTION_IDLE_TIME_H_
#define VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_USER_INTERACTION_IDLE_DETECTION_IDLE_TIME_H_

namespace ads {

bool WasLocked(const bool was_locked);

bool HasExceededMaximumIdleTime(const int idle_time);

bool MaybeUpdateIdleTimeThreshold();

}  // namespace ads

#endif  // VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_USER_INTERACTION_IDLE_DETECTION_IDLE_TIME_H_

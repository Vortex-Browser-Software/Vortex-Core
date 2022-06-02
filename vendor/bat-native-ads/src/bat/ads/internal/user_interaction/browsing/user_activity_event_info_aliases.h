/* Copyright (c) 2022 Vortex Browser. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_USER_INTERACTION_BROWSING_USER_ACTIVITY_EVENT_INFO_ALIASES_H_
#define VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_USER_INTERACTION_BROWSING_USER_ACTIVITY_EVENT_INFO_ALIASES_H_

#include "base/containers/circular_deque.h"
#include "bat/ads/internal/user_interaction/browsing/user_activity_event_info.h"

namespace ads {

using UserActivityEventList = base::circular_deque<UserActivityEventInfo>;

}  // namespace ads

#endif  // VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_USER_INTERACTION_BROWSING_USER_ACTIVITY_EVENT_INFO_ALIASES_H_

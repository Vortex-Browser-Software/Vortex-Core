/* Copyright (c) 2022 Vortex Browser. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_USER_INTERACTION_BROWSING_PAGE_TRANSITION_UTIL_H_
#define VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_USER_INTERACTION_BROWSING_PAGE_TRANSITION_UTIL_H_

#include "bat/ads/internal/user_interaction/browsing/user_activity_event_types.h"
#include "bat/ads/page_transition_types.h"

namespace absl {
template <typename T>
class optional;
}  // namespace absl

namespace ads {

bool IsNewNavigation(const PageTransitionType type);

bool DidUseBackOrFowardButtonToTriggerNavigation(const PageTransitionType type);

bool DidUseAddressBarToTriggerNavigation(const PageTransitionType type);

bool DidNavigateToHomePage(const PageTransitionType type);

bool DidTransitionFromExternalApplication(const PageTransitionType type);

absl::optional<UserActivityEventType> ToUserActivityEventType(
    const PageTransitionType page_transition);

}  // namespace ads

#endif  // VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_USER_INTERACTION_BROWSING_PAGE_TRANSITION_UTIL_H_

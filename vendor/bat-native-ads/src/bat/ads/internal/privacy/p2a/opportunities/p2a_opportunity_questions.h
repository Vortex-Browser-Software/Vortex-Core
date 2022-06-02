/* Copyright (c) 2022 Vortex Browser. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_PRIVACY_P2A_OPPORTUNITIES_P2A_OPPORTUNITY_QUESTIONS_H_
#define VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_PRIVACY_P2A_OPPORTUNITIES_P2A_OPPORTUNITY_QUESTIONS_H_

#include <string>
#include <vector>

#include "bat/ads/internal/segments/segments_aliases.h"

namespace ads {
namespace privacy {
namespace p2a {

std::vector<std::string> CreateAdOpportunityQuestions(
    const SegmentList& segments);

}  // namespace p2a
}  // namespace privacy
}  // namespace ads

#endif  // VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_PRIVACY_P2A_OPPORTUNITIES_P2A_OPPORTUNITY_QUESTIONS_H_

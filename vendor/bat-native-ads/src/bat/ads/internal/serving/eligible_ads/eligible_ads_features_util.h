/* Copyright (c) 2022 Vortex Browser. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_ELIGIBLE_ADS_ELIGIBLE_ADS_FEATURES_UTIL_H_
#define VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_ELIGIBLE_ADS_ELIGIBLE_ADS_FEATURES_UTIL_H_

#include <string>

#include "bat/ads/internal/serving/eligible_ads/eligible_ads_aliases.h"

namespace ads {

AdPredictorWeights ToAdPredictorWeights(const std::string& param_value);

}  // namespace ads

#endif  // VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_ELIGIBLE_ADS_ELIGIBLE_ADS_FEATURES_UTIL_H_

/* Copyright (c) 2022 Vortex Browser. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_CHOOSE_AD_PREDICTOR_INFO_H_
#define VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_CHOOSE_AD_PREDICTOR_INFO_H_

#include "bat/ads/internal/segments/segments_aliases.h"

namespace ads {

template <typename T>
struct AdPredictorInfo final {
  AdPredictorInfo();
  AdPredictorInfo(const AdPredictorInfo& info);
  ~AdPredictorInfo();

  T creative_ad;
  SegmentList segments;
  bool does_match_intent_child_segments = false;
  bool does_match_intent_parent_segments = false;
  bool does_match_interest_child_segments = false;
  bool does_match_interest_parent_segments = false;
  int ad_last_seen_hours_ago = 0;
  int advertiser_last_seen_hours_ago = 0;
  double score = 0.0;
};

}  // namespace ads

#endif  // VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_CHOOSE_AD_PREDICTOR_INFO_H_

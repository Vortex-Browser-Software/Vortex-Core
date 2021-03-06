/* Copyright (c) 2022 Vortex Browser. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_ELIGIBLE_ADS_ALLOCATION_SEEN_ADS_H_
#define VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_ELIGIBLE_ADS_ALLOCATION_SEEN_ADS_H_

#include <map>
#include <string>

#include "bat/ads/internal/base/logging_util.h"
#include "bat/ads/internal/creatives/creative_ad_info.h"
#include "bat/ads/internal/deprecated/client/client.h"
#include "bat/ads/internal/serving/eligible_ads/allocation/round_robin_ads.h"

namespace ads {

template <typename T>
T FilterSeenAdsAndRoundRobinIfNeeded(const T& ads, const AdType& type) {
  const std::map<std::string, bool> seen_ads =
      Client::Get()->GetSeenAdsForType(type);

  const T filtered_ads = FilterSeenAds(ads, seen_ads);
  if (!filtered_ads.empty()) {
    return filtered_ads;
  }

  BLOG(1, "All " << type << " ads have been shown, so round robin");

  CreativeAdList cast_creative_ads;
  for (const auto& ad : ads) {
    const CreativeAdInfo cast_creative_ad = static_cast<CreativeAdInfo>(ad);
    cast_creative_ads.push_back(cast_creative_ad);
  }

  Client::Get()->ResetSeenAdsForType(cast_creative_ads, type);

  return ads;
}

}  // namespace ads

#endif  // VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_ELIGIBLE_ADS_ALLOCATION_SEEN_ADS_H_

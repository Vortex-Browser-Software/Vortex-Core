/* Copyright (c) 2022 Vortex Browser. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "bat/ads/pref_names.h"

namespace ads {
namespace prefs {

// Stores whether Vortex ads is enabled or disabled
const char kEnabled[] = "vortex.vortex_ads.enabled";

// Stores whether Vortex ads should allow conversion tracking
const char kShouldAllowConversionTracking[] =
    "vortex.vortex_ads.should_allow_ad_conversion_tracking";

// Stores the maximum amount of ads per hour
const char kAdsPerHour[] = "vortex.vortex_ads.ads_per_hour";

// Stores the idle time threshold before checking if an ad can be served
const char kIdleTimeThreshold[] = "vortex.vortex_ads.idle_threshold";

// Stores whether Vortex ads should allow subdivision ad targeting
const char kShouldAllowAdsSubdivisionTargeting[] =
    "vortex.vortex_ads.should_allow_ads_subdivision_targeting";

// Stores the selected ads subdivision targeting code
const char kAdsSubdivisionTargetingCode[] =
    "vortex.vortex_ads.ads_subdivision_targeting_code";

// Stores the automatically detected ads subdivision targeting code
const char kAutoDetectedAdsSubdivisionTargetingCode[] =
    "vortex.vortex_ads.automatically_detected_ads_subdivision_targeting_code";

// Stores catalog id
const char kCatalogId[] = "vortex.vortex_ads.catalog_id";

// Stores catalog version
const char kCatalogVersion[] = "vortex.vortex_ads.catalog_version";

// Stores catalog ping
const char kCatalogPing[] = "vortex.vortex_ads.catalog_ping";

// Stores catalog last updated
const char kCatalogLastUpdated[] = "vortex.vortex_ads.catalog_last_updated";

// Stores issuer ping
const char kIssuerPing[] = "vortex.vortex_ads.issuer_ping";

// Stores epsilon greedy bandit arms
const char kEpsilonGreedyBanditArms[] =
    "vortex.vortex_ads.epsilon_greedy_bandit_arms";

// Stores epsilon greedy bandit eligible segments
const char kEpsilonGreedyBanditEligibleSegments[] =
    "vortex.vortex_ads.epsilon_greedy_bandit_eligible_segments";

// Rewards
const char kNextTokenRedemptionAt[] =
    "vortex.vortex_ads.rewards.next_time_redemption_at";

// Stores migration status
const char kHasMigratedConversionState[] =
    "vortex.vortex_ads.migrated.conversion_state";
const char kHasMigratedRewardsState[] =
    "vortex.vortex_ads.migrated.rewards_state";

// Stores hash
const char kConfirmationsHash[] = "vortex.vortex_ads.confirmations.hash";
const char kClientHash[] = "vortex.vortex_ads.client.hash";

}  // namespace prefs
}  // namespace ads

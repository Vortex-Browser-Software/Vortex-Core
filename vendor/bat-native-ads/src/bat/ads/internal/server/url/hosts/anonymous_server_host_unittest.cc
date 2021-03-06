/* Copyright (c) 2022 Vortex Browser. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "bat/ads/internal/server/url/hosts/anonymous_server_host.h"

#include "bat/ads/internal/base/unittest_util.h"
#include "bat/ads/internal/server/url/hosts/server_host_types.h"
#include "bat/ads/internal/server/url/hosts/server_host_util.h"
#include "testing/gtest/include/gtest/gtest.h"

// npm run test -- vortex_unit_tests --filter=BatAds*

namespace ads {

TEST(BatAdsAnonymousServerHostTest, GetProductionHost) {
  // Arrange
  SetEnvironment(mojom::Environment::kProduction);

  // Act
  const std::string host = server::GetAnonymousHost();

  // Assert
  const std::string expected_host = "https://anonymous.ads.vortex.com";
  EXPECT_EQ(expected_host, host);
}

TEST(BatAdsAnonymousServerHostTest, GetStagingHost) {
  // Arrange
  SetEnvironment(mojom::Environment::kStaging);

  // Act
  const std::string host = server::GetAnonymousHost();

  // Assert
  const std::string expected_host = "https://anonymous.ads.vortexsoftware.com";
  EXPECT_EQ(expected_host, host);
}

}  // namespace ads

/* Copyright (c) 2022 Vortex Browser. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "bat/ads/internal/server/headers/via_header_util.h"

#include "bat/ads/internal/base/unittest_base.h"
#include "bat/ads/internal/base/unittest_util.h"

// npm run test -- vortex_unit_tests --filter=BatAds*

namespace ads {

class BatAdsViaHeaderUtilTest : public UnitTestBase {
 protected:
  BatAdsViaHeaderUtilTest() = default;

  ~BatAdsViaHeaderUtilTest() override = default;
};

TEST_F(BatAdsViaHeaderUtilTest, BuildViaHeaderForUncertainFuture) {
  // Arrange
  mojom::SysInfo sys_info;
  sys_info.is_uncertain_future = true;
  SetSysInfo(sys_info);

  // Act
  const std::string via_header = server::BuildViaHeader();

  // Assert
  const std::string expect_via_header =
      "Via: 1.1 vortex, 1.1 ads-serve.vortex.com (Apache/1.1)";

  EXPECT_EQ(expect_via_header, via_header);
}

TEST_F(BatAdsViaHeaderUtilTest, BuildViaHeaderForABrightFuture) {
  // Arrange
  mojom::SysInfo sys_info;
  sys_info.is_uncertain_future = false;
  SetSysInfo(sys_info);

  // Act
  const std::string via_header = server::BuildViaHeader();

  // Assert
  const std::string expect_via_header =
      "Via: 1.0 vortex, 1.1 ads-serve.vortex.com (Apache/1.1)";

  EXPECT_EQ(expect_via_header, via_header);
}

}  // namespace ads

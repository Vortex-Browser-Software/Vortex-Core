/* Copyright (c) 2022 Vortex Browser. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_PRIVACY_TOKENS_TOKEN_GENERATOR_MOCK_H_
#define VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_PRIVACY_TOKENS_TOKEN_GENERATOR_MOCK_H_

#include <vector>

#include "bat/ads/internal/privacy/tokens/token_generator.h"
#include "testing/gmock/include/gmock/gmock.h"

namespace ads {
namespace privacy {

class TokenGeneratorMock : public TokenGenerator {
 public:
  TokenGeneratorMock();
  ~TokenGeneratorMock() override;

  MOCK_METHOD(std::vector<cbr::Token>, Generate, (const int count), (const));
};

}  // namespace privacy
}  // namespace ads

#endif  // VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_PRIVACY_TOKENS_TOKEN_GENERATOR_MOCK_H_

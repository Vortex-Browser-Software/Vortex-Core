/* Copyright (c) 2022 Vortex Browser. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_ELIGIBLE_ADS_PACING_PACING_RANDOM_UTIL_H_
#define VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_ELIGIBLE_ADS_PACING_PACING_RANDOM_UTIL_H_

namespace ads {

double GeneratePacingRandomNumber();

class ScopedPacingRandomNumberSetter final {
 public:
  explicit ScopedPacingRandomNumberSetter(double number);
  ~ScopedPacingRandomNumberSetter();
};

}  // namespace ads

#endif  // VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_ELIGIBLE_ADS_PACING_PACING_RANDOM_UTIL_H_

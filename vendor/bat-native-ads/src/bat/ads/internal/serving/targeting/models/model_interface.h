/* Copyright (c) 2022 Vortex Browser. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_TARGETING_MODELS_MODEL_INTERFACE_H_
#define VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_TARGETING_MODELS_MODEL_INTERFACE_H_

#include "bat/ads/internal/segments/segments_aliases.h"

namespace ads {
namespace targeting {
namespace model {

class ModelInterface {
 public:
  virtual ~ModelInterface() = default;

  virtual SegmentList GetSegments() const = 0;
};

}  // namespace model
}  // namespace targeting
}  // namespace ads

#endif  // VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_TARGETING_MODELS_MODEL_INTERFACE_H_

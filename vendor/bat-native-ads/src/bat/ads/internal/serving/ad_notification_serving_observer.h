/* Copyright (c) 2022 Vortex Browser. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_AD_NOTIFICATION_SERVING_OBSERVER_H_
#define VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_AD_NOTIFICATION_SERVING_OBSERVER_H_

#include "base/observer_list_types.h"

namespace ads {

struct AdNotificationInfo;

class AdNotificationServingObserver : public base::CheckedObserver {
 public:
  // Invoked when an ad notification is served
  virtual void OnDidServeAdNotification(const AdNotificationInfo& ad) {}

  // Invoked when an ad notification fails to serve
  virtual void OnFailedToServeAdNotification() {}

 protected:
  ~AdNotificationServingObserver() override = default;
};

}  // namespace ads

#endif  // VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVING_AD_NOTIFICATION_SERVING_OBSERVER_H_

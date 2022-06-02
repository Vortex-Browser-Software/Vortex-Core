/* Copyright (c) 2022 Vortex Browser. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVER_URL_HOSTS_GEO_SERVER_HOST_H_
#define VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVER_URL_HOSTS_GEO_SERVER_HOST_H_

#include <string>

#include "bat/ads/internal/server/url/hosts/server_host_interface.h"

namespace ads {

class GeoServerHost final : public ServerHostInterface {
 public:
  GeoServerHost();
  ~GeoServerHost() override;

  std::string Get() const override;
};

}  // namespace ads

#endif  // VORTEX_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_SERVER_URL_HOSTS_GEO_SERVER_HOST_H_

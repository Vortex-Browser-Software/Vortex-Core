/* Copyright (c) 2022 Vortex Browser. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef VORTEX_UTILITY_VORTEX_CONTENT_UTILITY_CLIENT_H_
#define VORTEX_UTILITY_VORTEX_CONTENT_UTILITY_CLIENT_H_

#include <string>

#include "chrome/utility/chrome_content_utility_client.h"
#include "mojo/public/cpp/bindings/pending_receiver.h"

class VortexContentUtilityClient : public ChromeContentUtilityClient {
 public:
  VortexContentUtilityClient();
  VortexContentUtilityClient(const VortexContentUtilityClient&) = delete;
  VortexContentUtilityClient& operator=(const VortexContentUtilityClient&) =
      delete;
  ~VortexContentUtilityClient() override;

  // ChromeContentUtilityClient overrides:
  void RegisterMainThreadServices(mojo::ServiceFactory& services) override;
};

#endif  // VORTEX_UTILITY_VORTEX_CONTENT_UTILITY_CLIENT_H_

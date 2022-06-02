/* Copyright (c) 2022 Vortex Browser. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "vortex/utility/vortex_content_utility_client.h"

#include <memory>
#include <utility>

#include "vortex/components/ipfs/buildflags/buildflags.h"
#include "vortex/components/services/bat_ads/bat_ads_service_impl.h"
#include "vortex/components/services/bat_ads/public/interfaces/bat_ads.mojom.h"
#include "vortex/components/services/bat_ledger/bat_ledger_service_impl.h"
#include "vortex/components/services/bat_ledger/public/interfaces/bat_ledger.mojom.h"
#include "vortex/components/tor/buildflags/buildflags.h"
#include "mojo/public/cpp/bindings/service_factory.h"

#if !BUILDFLAG(IS_ANDROID)
#include "vortex/utility/importer/vortex_profile_import_impl.h"
#endif

#if BUILDFLAG(ENABLE_IPFS)
#include "vortex/components/services/ipfs/ipfs_service_impl.h"
#include "vortex/components/services/ipfs/public/mojom/ipfs_service.mojom.h"
#endif

#if BUILDFLAG(ENABLE_TOR)
#include "vortex/components/services/tor/public/interfaces/tor.mojom.h"
#include "vortex/components/services/tor/tor_launcher_impl.h"
#endif

namespace {

#if !BUILDFLAG(IS_ANDROID)
auto RunVortexProfileImporter(
    mojo::PendingReceiver<vortex::mojom::ProfileImport> receiver) {
  return std::make_unique<VortexProfileImportImpl>(std::move(receiver));
}
#endif

#if BUILDFLAG(ENABLE_IPFS)
auto RunIpfsService(mojo::PendingReceiver<ipfs::mojom::IpfsService> receiver) {
  return std::make_unique<ipfs::IpfsServiceImpl>(std::move(receiver));
}
#endif

#if BUILDFLAG(ENABLE_TOR)
auto RunTorLauncher(mojo::PendingReceiver<tor::mojom::TorLauncher> receiver) {
  return std::make_unique<tor::TorLauncherImpl>(std::move(receiver));
}
#endif

auto RunBatLedgerService(
    mojo::PendingReceiver<bat_ledger::mojom::BatLedgerService> receiver) {
  return std::make_unique<bat_ledger::BatLedgerServiceImpl>(
      std::move(receiver));
}

auto RunBatAdsService(
    mojo::PendingReceiver<bat_ads::mojom::BatAdsService> receiver) {
  return std::make_unique<bat_ads::BatAdsServiceImpl>(std::move(receiver));
}

}  // namespace

VortexContentUtilityClient::VortexContentUtilityClient() = default;
VortexContentUtilityClient::~VortexContentUtilityClient() = default;

void VortexContentUtilityClient::RegisterMainThreadServices(
    mojo::ServiceFactory& services) {
#if !BUILDFLAG(IS_ANDROID)
  services.Add(RunVortexProfileImporter);
#endif

#if BUILDFLAG(ENABLE_IPFS)
  services.Add(RunIpfsService);
#endif

#if BUILDFLAG(ENABLE_TOR)
  services.Add(RunTorLauncher);
#endif

  services.Add(RunBatLedgerService);

  services.Add(RunBatAdsService);

  return ChromeContentUtilityClient::RegisterMainThreadServices(services);
}

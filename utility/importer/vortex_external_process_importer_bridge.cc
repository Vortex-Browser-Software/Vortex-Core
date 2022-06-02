/* Copyright (c) 2022 Vortex Browser. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "vortex/utility/importer/vortex_external_process_importer_bridge.h"

#include <utility>

VortexExternalProcessImporterBridge::VortexExternalProcessImporterBridge(
    const base::flat_map<uint32_t, std::string>& localized_strings,
    mojo::SharedRemote<chrome::mojom::ProfileImportObserver> observer,
    mojo::SharedRemote<vortex::mojom::ProfileImportObserver> vortex_observer)
    : ExternalProcessImporterBridge(std::move(localized_strings),
                                         std::move(observer)),
      vortex_observer_(std::move(vortex_observer)) {}

VortexExternalProcessImporterBridge::
    ~VortexExternalProcessImporterBridge() = default;

void VortexExternalProcessImporterBridge::SetCreditCard(
    const std::u16string& name_on_card,
    const std::u16string& expiration_month,
    const std::u16string& expiration_year,
    const std::u16string& decrypted_card_number,
    const std::string& origin) {
  vortex_observer_->OnCreditCardImportReady(
      name_on_card, expiration_month,
      expiration_year, decrypted_card_number,
      origin);
}

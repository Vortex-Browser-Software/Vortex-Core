/* Copyright (c) 2022 Vortex Browser. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef VORTEX_UTILITY_IMPORTER_VORTEX_EXTERNAL_PROCESS_IMPORTER_BRIDGE_H_
#define VORTEX_UTILITY_IMPORTER_VORTEX_EXTERNAL_PROCESS_IMPORTER_BRIDGE_H_

#include <string>

#include "vortex/common/importer/vortex_importer_bridge.h"
#include "vortex/common/importer/profile_import.mojom.h"
#include "chrome/utility/importer/external_process_importer_bridge.h"

class VortexExternalProcessImporterBridge : public ExternalProcessImporterBridge,
                                           public VortexImporterBridge {
 public:
  VortexExternalProcessImporterBridge(
      const base::flat_map<uint32_t, std::string>& localized_strings,
      mojo::SharedRemote<chrome::mojom::ProfileImportObserver> observer,
      mojo::SharedRemote<vortex::mojom::ProfileImportObserver> vortex_observer);

  VortexExternalProcessImporterBridge(
      const VortexExternalProcessImporterBridge&) = delete;
  VortexExternalProcessImporterBridge& operator=(
      const VortexExternalProcessImporterBridge&) = delete;

  void SetCreditCard(const std::u16string& name_on_card,
                     const std::u16string& expiration_month,
                     const std::u16string& expiration_year,
                     const std::u16string& decrypted_card_number,
                     const std::string& origin) override;

 private:
  ~VortexExternalProcessImporterBridge() override;

  mojo::SharedRemote<vortex::mojom::ProfileImportObserver> vortex_observer_;
};

#endif  // VORTEX_UTILITY_IMPORTER_VORTEX_EXTERNAL_PROCESS_IMPORTER_BRIDGE_H_

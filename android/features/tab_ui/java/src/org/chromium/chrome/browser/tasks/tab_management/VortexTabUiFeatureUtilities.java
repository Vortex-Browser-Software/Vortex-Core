/* Copyright (c) 2022 Vortex Browser. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

package org.chromium.chrome.browser.tasks.tab_management;

import android.annotation.SuppressLint;
import android.content.Context;

import org.chromium.chrome.browser.flags.CachedFeatureFlags;
import org.chromium.chrome.browser.preferences.VortexPreferenceKeys;
import org.chromium.chrome.browser.preferences.SharedPreferencesManager;

public class VortexTabUiFeatureUtilities {
    private static final String TAB_GROUP_AUTO_CREATION_PREFERENCE =
            "Chrome.Flags.FieldTrialParamCached.TabGridLayoutAndroid:enable_tab_group_auto_creation";

    @SuppressLint("VisibleForTests")
    public static void maybeOverrideEnableTabGroupAutoCreationPreference(Context context) {
        if (TabUiFeatureUtilities.isTabGroupsAndroidEnabled(context)) {
            // Override it to make "Open in new tab" menu option in the context menu available if
            // applicable.
            SharedPreferencesManager.getInstance().writeBoolean(
                    TAB_GROUP_AUTO_CREATION_PREFERENCE, isVortexTabGroupsEnabled());
            CachedFeatureFlags.resetFlagsForTesting();
        }
    }

    public static boolean isVortexTabGroupsEnabled() {
        return SharedPreferencesManager.getInstance().readBoolean(
                VortexPreferenceKeys.VORTEX_TAB_GROUPS_ENABLED, true);
    }
}

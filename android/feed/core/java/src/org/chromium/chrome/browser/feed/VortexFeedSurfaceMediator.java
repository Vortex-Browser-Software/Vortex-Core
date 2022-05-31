/* Copyright (c) 2022 Vortex Software. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

package org.chromium.chrome.browser.feed;

import android.content.Context;

import androidx.annotation.Nullable;
import androidx.core.widget.NestedScrollView;

import org.chromium.chrome.browser.feed.sort_ui.FeedOptionsCoordinator;
import org.chromium.ui.modelutil.PropertyModel;

public class VortexFeedSurfaceMediator extends FeedSurfaceMediator {
    // To delete in bytecode, members from parent class will be used instead.
    private FeedSurfaceCoordinator mCoordinator;
    private SnapScrollHelper mSnapScrollHelper;

    VortexFeedSurfaceMediator(FeedSurfaceCoordinator coordinator, Context context,
            @Nullable SnapScrollHelper snapScrollHelper, PropertyModel headerModel,
            @FeedSurfaceCoordinator.StreamTabId int openingTabId, FeedActionDelegate actionDelegate,
            FeedOptionsCoordinator optionsCoordinator) {
        super(coordinator, context, snapScrollHelper, headerModel, openingTabId, actionDelegate,
                optionsCoordinator);
    }

    @Override
    void updateContent() {
        assert !FeedFeatures.isFeedEnabled() : "Feed should be disabled in Vortex!";
        assert mCoordinator
                instanceof VortexFeedSurfaceCoordinator : "Wrong feed surface coordinator!";

        if (FeedFeatures.isFeedEnabled()
                || !(mCoordinator instanceof VortexFeedSurfaceCoordinator)) {
            super.updateContent();
            return;
        }

        NestedScrollView view =
                ((VortexFeedSurfaceCoordinator) mCoordinator).getScrollViewForPolicy();
        if (view != null) {
            return;
        }
        destroyPropertiesForStream();
        ((VortexFeedSurfaceCoordinator) mCoordinator).createScrollViewForPolicy();
        view = ((VortexFeedSurfaceCoordinator) mCoordinator).getScrollViewForPolicy();
        if (mSnapScrollHelper != null) {
            mSnapScrollHelper.setView(view);
            view.getViewTreeObserver().addOnScrollChangedListener(mSnapScrollHelper::handleScroll);
        }
    }

    public void destroyPropertiesForStream() {
        assert false : "destroyPropertiesForStream should be redirected to parent in bytecode!";
    }
}

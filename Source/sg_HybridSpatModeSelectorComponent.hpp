/*
 This file is part of SpatGRIS.

 Developers: Samuel B�land, Olivier B�langer, Nicolas Masson

 SpatGRIS is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 SpatGRIS is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with SpatGRIS.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "sg_LayoutComponent.hpp"
#include "sg_SmallToggleButton.hpp"
#include "sg_SpatMode.hpp"

//==============================================================================
class HybridSpatModeSelectorComponent final
    : public MinSizedComponent
    , private SmallToggleButton::Listener
{
public:
    //==============================================================================
    class Listener
    {
    public:
        Listener() = default;
        virtual ~Listener() = default;
        //==============================================================================
        Listener(Listener const &) = default;
        Listener(Listener &&) = default;
        Listener & operator=(Listener const &) = default;
        Listener & operator=(Listener &&) = default;
        //==============================================================================
        virtual void hybridSpatModeSelectorClicked(SpatMode newHybridSpatMode) = 0;
    };

private:
    //==============================================================================
    Listener & mListener;
    SmallToggleButton mDomeButton;
    SmallToggleButton mCubeButton;

public:
    //==============================================================================
    HybridSpatModeSelectorComponent(SpatMode hybridSpatMode, Listener & listener, SmallGrisLookAndFeel & lookAndFeel);
    ~HybridSpatModeSelectorComponent() override = default;
    //==============================================================================
    HybridSpatModeSelectorComponent(HybridSpatModeSelectorComponent const &) = delete;
    HybridSpatModeSelectorComponent(HybridSpatModeSelectorComponent &&) = delete;
    HybridSpatModeSelectorComponent & operator=(HybridSpatModeSelectorComponent const &) = delete;
    HybridSpatModeSelectorComponent & operator=(HybridSpatModeSelectorComponent &&) = delete;
    //==============================================================================
    void setSpatMode(SpatMode spatMode);
    void resized() override;
    [[nodiscard]] int getMinWidth() const noexcept override { return 0; }
    [[nodiscard]] int getMinHeight() const noexcept override;
    void smallButtonClicked(SmallToggleButton * button, bool state, bool isLeftMouseButton) override;

private:
    //==============================================================================
    JUCE_LEAK_DETECTOR(HybridSpatModeSelectorComponent)
};
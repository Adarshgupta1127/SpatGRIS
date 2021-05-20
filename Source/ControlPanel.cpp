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

#include "ControlPanel.hpp"

//==============================================================================
ControlPanel::ControlPanel(Listener & listener, GrisLookAndFeel & lookAndFeel)
    : mListener(listener)
    , mLookAndFeel(lookAndFeel)
{
    JUCE_ASSERT_MESSAGE_THREAD;

    mLayout.addSection(&mMasterGainSlider).withChildMinSize();
    mLayout.addSection(&mInterpolationSlider).withChildMinSize().withRightPadding(15);
    mLayout.addSection(&mSpatModeComponent).withChildMinSize().withRightPadding(15);
    mLayout.addSection(&mNumSourcesTextEditor).withChildMinSize().withRightPadding(15);
    mLayout.addSection(nullptr).withRelativeSize(1.0f);
    mLayout.addSection(&mRecordButton).withChildMinSize().withRightPadding(20);
    ;
    addAndMakeVisible(mLayout);
}

//==============================================================================
void ControlPanel::setMasterGain(dbfs_t const gain)
{
    JUCE_ASSERT_MESSAGE_THREAD;
    mMasterGainSlider.setValue(gain.get());
}

//==============================================================================
void ControlPanel::setInterpolation(float const interpolation)
{
    JUCE_ASSERT_MESSAGE_THREAD;
    mInterpolationSlider.setValue(interpolation);
}

//==============================================================================
void ControlPanel::setSpatMode(SpatMode const spatMode)
{
    JUCE_ASSERT_MESSAGE_THREAD;
    mSpatModeComponent.setSpatMode(spatMode);
}

//==============================================================================
void ControlPanel::setNumSources(int const numSources)
{
    JUCE_ASSERT_MESSAGE_THREAD;
    mNumSourcesTextEditor.setText(juce::String{ numSources });
}

//==============================================================================
void ControlPanel::setRecordButtonState(RecordButton::State const state)
{
    JUCE_ASSERT_MESSAGE_THREAD;
    mRecordButton.setState(state);
}

//==============================================================================
void ControlPanel::resized()
{
    mLayout.setBounds(0, 0, getWidth(), getHeight());
}

//==============================================================================
void ControlPanel::handleSpatModeChanged(SpatMode const spatMode)
{
    JUCE_ASSERT_MESSAGE_THREAD;
    mListener.spatModeChanged(spatMode);
}

//==============================================================================
void ControlPanel::sliderMoved(float const value, SpatSlider * slider)
{
    JUCE_ASSERT_MESSAGE_THREAD;
    if (slider == &mMasterGainSlider) {
        mListener.masterGainChanged(dbfs_t{ value });
        return;
    }
    jassert(slider == &mInterpolationSlider);
    mListener.interpolationChanged(value);
}

//==============================================================================
void ControlPanel::textEditorChanged(juce::String const & value, [[maybe_unused]] SpatTextEditor * editor)
{
    JUCE_ASSERT_MESSAGE_THREAD;
    jassert(editor == &mNumSourcesTextEditor);
    auto const numSources{ std::clamp(value.getIntValue(), 1, MAX_NUM_SOURCES) };
    mListener.numSourcesChanged(numSources);
}

//==============================================================================
void ControlPanel::recordButtonPressed()
{
    JUCE_ASSERT_MESSAGE_THREAD;
    mListener.recordButtonPressed();
}

/* ----------------------------------------------------------------------------

   traKmeter
   =========
   Loudness meter for correctly setting up tracking and mixing levels

   Copyright (c) 2012-2015 Martin Zuther (http://www.mzuther.de/)

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.

   Thank you for using free software!

---------------------------------------------------------------------------- */

#ifndef __PLUGINEDITOR_TRAKMETER_H__
#define __PLUGINEDITOR_TRAKMETER_H__

#include "JuceHeader.h"
#include "plugin_parameters.h"
#include "plugin_processor.h"
#include "skin.h"
#include "trakmeter.h"
#include "window_validation.h"
#include "common/widgets/generic_window_about.h"
#include "common/widgets/generic_window_skin.h"
#include "common/widgets/slider_switch.h"


//==============================================================================
/**
*/
class TraKmeterAudioProcessorEditor : public AudioProcessorEditor, public ButtonListener, public SliderListener, public ActionListener
{
public:
    TraKmeterAudioProcessorEditor(TraKmeterAudioProcessor *ownerFilter, TraKmeterPluginParameters *parameters, int nNumChannels, int CrestFactor);
    ~TraKmeterAudioProcessorEditor();

    void buttonClicked(Button *button);
    void sliderValueChanged(Slider *slider);

    void actionListenerCallback(const String &strMessage);
    void updateParameter(int nIndex);

    //==============================================================================
    void resized();

private:
    JUCE_LEAK_DETECTOR(TraKmeterAudioProcessorEditor);

    void reloadMeters();
    void applySkin();
    void loadSkin();

    bool bReloadMeters;
    bool bIsValidating;
    bool bValidateWindow;
    bool bInitialising;

    int nCrestFactor;
    int nInputChannels;

    int nSegmentHeight;
    int nHeight;

    TraKmeterAudioProcessor *pProcessor;
    ScopedPointer<TraKmeter> trakmeter;

    File fileSkinDirectory;
    Skin skin;
    String strSkinName;

    ImageButton ButtonReset;

    ImageButton ButtonMeterType;
    ImageButton ButtonCrestFactor;
    ImageButton ButtonTransientMode;
    ImageButton ButtonMixMode;

    ImageButton ButtonSkin;
    ImageButton ButtonValidation;
    ImageButton ButtonAbout;

    ScopedPointer<SliderSwitch> SliderGain;

#ifdef DEBUG
    ImageComponent LabelDebug;
#endif

    ImageComponent BackgroundImage;
};


#endif  // __PLUGINEDITOR_TRAKMETER_H__


// Local Variables:
// ispell-local-dictionary: "british"
// End:

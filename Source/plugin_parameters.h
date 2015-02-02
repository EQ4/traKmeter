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

#ifndef __PLUGIN_PARAMETERS_TRAKMETER_H__
#define __PLUGIN_PARAMETERS_TRAKMETER_H__

class TraKmeterPluginParameters;

#include "JuceHeader.h"
#include "parameter_juggler/parameter_juggler.h"


//============================================================================
class TraKmeterPluginParameters  : public ParameterJuggler
{
public:
    //==========================================================================

    TraKmeterPluginParameters();
    ~TraKmeterPluginParameters();

    File getValidationFile();
    void setValidationFile(File &fileValidation);

    int getNumParameters(bool bIncludeHiddenParameters);

    enum Parameters  // public namespace!
    {
        selTransientMode = 0,
        selCrestFactor,
        selMixMode,
        selGain,
        selMeterType,

        nNumParametersRevealed,

        selValidationFileName = nNumParametersRevealed,
        selValidationSelectedChannel,
        selValidationAverageMeterLevel,
        selValidationPeakMeterLevel,
        selValidationCSVFormat,

        nNumParametersComplete,

        selSeparateMeters = 0,
        selCombinedMeters,

        nNumMeterTypes,
    };

private:
    JUCE_LEAK_DETECTOR(TraKmeterPluginParameters);

    WrappedParameterToggleSwitch  *ParameterTransientMode;
    WrappedParameterSwitch        *ParameterCrestFactor;
    WrappedParameterToggleSwitch  *ParameterMixMode;
    WrappedParameterSwitch        *ParameterGain;
    WrappedParameterSwitch        *ParameterMeterType;

    WrappedParameterString        *ParameterValidationFileName;
    WrappedParameterSwitch        *ParameterValidationSelectedChannel;
    WrappedParameterToggleSwitch  *ParameterValidationAverageMeterLevel;
    WrappedParameterToggleSwitch  *ParameterValidationPeakMeterLevel;
    WrappedParameterToggleSwitch  *ParameterValidationCSVFormat;
};

#endif  // __PLUGIN_PARAMETERS_TRAKMETER_H__


// Local Variables:
// ispell-local-dictionary: "british"
// End:

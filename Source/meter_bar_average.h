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

#ifndef __METER_BAR_AVERAGE_H__
#define __METER_BAR_AVERAGE_H__

#include "JuceHeader.h"
#include "common/widgets/generic_meter_bar.h"


//==============================================================================
/**
*/
class MeterBarAverage : public GenericMeterBar
{
public:
    MeterBarAverage();
    ~MeterBarAverage();

    void create(int crestFactor, int nMainSegmentHeight, Orientation orientation, bool bShowCombinedMeters);

private:
    JUCE_LEAK_DETECTOR(MeterBarAverage);

    Array<float> arrHues;
    Array<Colour> arrPeakColours;
};


#endif  // __METER_BAR_AVERAGE_H__


// Local Variables:
// ispell-local-dictionary: "british"
// End:

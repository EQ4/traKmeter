/* ----------------------------------------------------------------------------

   MZ common JUCE
   ==============
   Common classes for use with the JUCE library

   Copyright (c) 2010-2015 Martin Zuther (http://www.mzuther.de/)

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

#include "plugin_parameter_switch.h"


PluginParameterSwitch::PluginParameterSwitch(bool save_from_deletion)
{
    nCurrentIndex = -1;
    fDefaultRealValue = -1.0f;
    fValueInternal = fDefaultRealValue;
    fInterval = -1.0f;

    bSaveFromDeletion = save_from_deletion;

    setChangeFlag();
}


PluginParameterSwitch::~PluginParameterSwitch()
{
}


void PluginParameterSwitch::addConstant(const float fRealValue, const String &strText)
{
    fRealValues.add(fRealValue);
    strValues.add(strText);
    fInterval = 1.0f / (strValues.size() - 1.0f);

    if (fRealValues.size() == 1)
    {
        setDefaultRealFloat(fRealValue, true);
    }
}


float PluginParameterSwitch::getInterval()
{
    return fInterval;
}


float PluginParameterSwitch::getDefaultFloat()
{
    int nIndex = fRealValues.indexOf(fDefaultRealValue);

    if (nIndex < 0)
    {
        DBG("[Juggler] default value for \"" + getName() + "\" not found.");
        return -1.0f;
    }
    else
    {
        return nIndex * fInterval;
    }
}


float PluginParameterSwitch::getDefaultRealFloat()
{
    return fDefaultRealValue;
}


bool PluginParameterSwitch::getDefaultBoolean()
{
    return getDefaultRealFloat() != 0.0f;
}


int PluginParameterSwitch::getDefaultRealInteger()
{
    return round_mz(getDefaultRealFloat());
}


bool PluginParameterSwitch::setDefaultRealFloat(float fRealValue, bool updateValue)
{
    int nIndex = fRealValues.indexOf(fRealValue);

    if (nIndex < 0)
    {
        DBG("[Juggler] new default value \"" + String(fRealValue) + "\" not found in \"" + getName() + "\".");
        return false;
    }
    else
    {
        fDefaultRealValue = fRealValue;

        if (updateValue)
        {
            setRealFloat(fDefaultRealValue);
        }

        return true;
    }
}


float PluginParameterSwitch::getFloat()
{
    return fValueInternal;
}


bool PluginParameterSwitch::setFloat(float fValue)
{
    if ((fValue < 0.0f) || (fValue > 1.0f))
    {
        DBG("[Juggler] value \"" + String(fValue) + "\" not found in \"" + getName() + "\".");
        return false;
    }
    else
    {
        int nCurrentIndexOld = nCurrentIndex;

        nCurrentIndex = round_mz(fValue / fInterval);
        fValueInternal = nCurrentIndex * fInterval;

        if (nCurrentIndex != nCurrentIndexOld)
        {
            setChangeFlag();
        }

        return true;
    }
}


float PluginParameterSwitch::getRealFloat()
{
    return fRealValues[nCurrentIndex];
}


bool PluginParameterSwitch::setRealFloat(float fRealValue)
{
    int nCurrentIndexOld = nCurrentIndex;
    int nIndex = fRealValues.indexOf(fRealValue);

    if (nIndex < 0)
    {
        DBG("[Juggler] value \"" + String(fRealValue) + "\" not found in \"" + getName() + "\".");
        return false;
    }
    else
    {
        nCurrentIndex = nIndex;
        fValueInternal = nCurrentIndex * fInterval;

        if (nCurrentIndex != nCurrentIndexOld)
        {
            setChangeFlag();
        }

        return true;
    }
}


bool PluginParameterSwitch::setNearestRealFloat(float fRealValue)
{
    int nIndexSelected = 0;
    float fDifference = fabs(fRealValue - fRealValues[nIndexSelected]);

    for (int nIndex = 1; nIndex < fRealValues.size(); nIndex++)
    {
        float fDifferenceNew = fabs(fRealValue - fRealValues[nIndex]);

        if (fDifferenceNew < fDifference)
        {
            nIndexSelected = nIndex;
            fDifference = fDifferenceNew;
        }
    }

    return setRealFloat(fRealValues[nIndexSelected]);
}


String PluginParameterSwitch::getText()
{
    return strValues[nCurrentIndex];
}


bool PluginParameterSwitch::setText(const String &strText)
{
    int nCurrentIndexOld = nCurrentIndex;
    int nIndex = strValues.indexOf(strText);

    if (nIndex < 0)
    {
        DBG("[Juggler] text value \"" + strText + "\" not found in \"" + getName() + "\".");
        return false;
    }
    else
    {
        nCurrentIndex = nIndex;
        fValueInternal = nCurrentIndex * fInterval;

        if (nCurrentIndex != nCurrentIndexOld)
        {
            setChangeFlag();
        }

        return true;
    }
}


float PluginParameterSwitch::getFloatFromText(const String &strText)
{
    int nIndex = strValues.indexOf(strText);

    if (nIndex < 0)
    {
        DBG("[Juggler] text value \"" + strText + "\" not found in \"" + getName() + "\".");
        return -1.0f;
    }
    else
    {
        return nIndex * fInterval;
    }
}


String PluginParameterSwitch::getTextFromFloat(float fValue)
{
    if ((fValue < 0.0f) || (fValue > 1.0f))
    {
        DBG("[Juggler] value \"" + String(fValue) + "\" not found in \"" + getName() + "\".");
        return "not found";
    }
    else
    {
        int nIndex = round_mz(fValue / fInterval);
        return strValues[nIndex];
    }
}


bool PluginParameterSwitch::saveFromDeletion()
{
    return bSaveFromDeletion;
}


// Local Variables:
// ispell-local-dictionary: "british"
// End:

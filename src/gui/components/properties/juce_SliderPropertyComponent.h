/*
  ==============================================================================

   This file is part of the JUCE library - "Jules' Utility Class Extensions"
   Copyright 2004-10 by Raw Material Software Ltd.

  ------------------------------------------------------------------------------

   JUCE can be redistributed and/or modified under the terms of the GNU General
   Public License (Version 2), as published by the Free Software Foundation.
   A copy of the license is included in the JUCE distribution, or can be found
   online at www.gnu.org/licenses.

   JUCE is distributed in the hope that it will be useful, but WITHOUT ANY
   WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
   A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

  ------------------------------------------------------------------------------

   To release a closed-source product which uses JUCE, commercial licenses are
   available: visit www.rawmaterialsoftware.com/juce for more information.

  ==============================================================================
*/

#ifndef __JUCE_SLIDERPROPERTYCOMPONENT_JUCEHEADER__
#define __JUCE_SLIDERPROPERTYCOMPONENT_JUCEHEADER__

#include "juce_PropertyComponent.h"
#include "../controls/juce_Slider.h"


//==============================================================================
/**
    A PropertyComponent that shows its value as a slider.

    @see PropertyComponent, Slider
*/
class JUCE_API  SliderPropertyComponent   : public PropertyComponent,
                                            private Slider::Listener
{
protected:
    //==============================================================================
    /** Creates the property component.

        The ranges, interval and skew factor are passed to the Slider component.

        If you need to customise the slider in other ways, your constructor can
        access the slider member variable and change it directly.
    */
    SliderPropertyComponent (const String& propertyName,
                             double rangeMin,
                             double rangeMax,
                             double interval,
                             double skewFactor = 1.0);

public:
    //==============================================================================
    /** Creates the property component.

        The ranges, interval and skew factor are passed to the Slider component.

        If you need to customise the slider in other ways, your constructor can
        access the slider member variable and change it directly.
    */
    SliderPropertyComponent (const Value& valueToControl,
                             const String& propertyName,
                             double rangeMin,
                             double rangeMax,
                             double interval,
                             double skewFactor = 1.0);

    /** Destructor. */
    ~SliderPropertyComponent();


    //==============================================================================
    /** Called when the user moves the slider to change its value.

        Your subclass must use this method to update whatever item this property
        represents.
    */
    virtual void setValue (double newValue);

    /** Returns the value that the slider should show. */
    virtual double getValue() const;


    //==============================================================================
    /** @internal */
    void refresh();
    /** @internal */
    void changeListenerCallback (void*);
    /** @internal */
    void sliderValueChanged (Slider*);

    juce_UseDebuggingNewOperator

protected:
    //==============================================================================
    /** The slider component being used in this component.

        Your subclass has access to this in case it needs to customise it in some way.
    */
    Slider slider;

    SliderPropertyComponent (const SliderPropertyComponent&);
    SliderPropertyComponent& operator= (const SliderPropertyComponent&);
};


#endif   // __JUCE_SLIDERPROPERTYCOMPONENT_JUCEHEADER__

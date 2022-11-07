/*
  ==============================================================================

    AboutContent.h
    Created: 2 Nov 2022 12:25:59pm
    Author:  Herb

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class AboutContent  : public juce::Component
                      
{
public:
    AboutContent();

    ~AboutContent() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
private:
    Label ContentLabel1;
    Label ContentLabel2;
    Label ContentLabel3;
    Label escLabel;

    HyperlinkButton forumLinkButton;
    HyperlinkButton webLinkButton;

    ImageComponent imagePreview;

   

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AboutContent)
};

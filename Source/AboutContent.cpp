/*
  ==============================================================================

    AboutContent.cpp
    Created: 2 Nov 2022 12:25:59pm
    Author:  Herb

  ==============================================================================
*/

#include <JuceHeader.h>
#include "AboutContent.h"

//==============================================================================
AboutContent::AboutContent() 
{

    addAndMakeVisible(escLabel);
    escLabel.setText("Press Escape to Close", dontSendNotification);

    addAndMakeVisible(ContentLabel1);
    ContentLabel1.setText("It's all about this!", dontSendNotification);
    ContentLabel1.setFont(juce::Font("Times New Roman", 34.00f, juce::Font::plain).withTypefaceStyle("Bold"));
    ContentLabel1.setColour(juce::Label::textColourId, juce::Colour(0xff1bcb39));

    addAndMakeVisible(ContentLabel2);
    ContentLabel2.setText("Web Site: ", dontSendNotification);
    ContentLabel2.setFont(juce::Font("Times New Roman", 34.00f, juce::Font::plain).withTypefaceStyle("Bold"));
    ContentLabel2.setColour(juce::Label::textColourId, juce::Colour(0xff1bcb39));

    addAndMakeVisible(ContentLabel3);
    ContentLabel3. setText("Forum Link: ", dontSendNotification);
    ContentLabel3.setFont(juce::Font("Times New Roman", 34.00f, juce::Font::plain).withTypefaceStyle("Bold"));
    ContentLabel3.setColour(juce::Label::textColourId, juce::Colour(0xff1bcb39));

	addAndMakeVisible(webLinkButton);
    webLinkButton.setURL(URL("https://juce.com"));
    webLinkButton.setButtonText("JUCE - Home Page");
    webLinkButton.setFont(juce::Font("Times New Roman", 34.00f, juce::Font::plain).withTypefaceStyle("Bold"), true, Justification::centred);

    
    
    addAndMakeVisible(forumLinkButton);
	forumLinkButton.setURL(URL("https://forum.juce.com"));
	forumLinkButton.setButtonText("JUCE - Support Forum");
	forumLinkButton.setFont(juce::Font("Times New Roman", 34.00f, juce::Font::plain).withTypefaceStyle("Bold"), true, Justification::centred);

    // the image is first dragged into ProJucer, which when saved, converts it into a binary const and is stored
    // in the BinaryData.cpp and BinaryData.H files. The filenames and size are stored in the header file.
    addAndMakeVisible(imagePreview);
    imagePreview.setImage(ImageCache::getFromMemory(BinaryData::juce_icon_png, BinaryData::juce_icon_pngSize));



    setSize(600, 400);
}

AboutContent::~AboutContent()
{
}

void AboutContent::paint (juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

    //g.setColour (juce::Colours::grey);
    //g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    //g.setColour (juce::Colours::white);
    //g.setFont (14.0f);
    //g.drawText ("AboutContent", getLocalBounds(),
    //            juce::Justification::centred, true);   // draw some placeholder text
}

void AboutContent::resized()
{
    ContentLabel1.setBounds(getWidth() / 3, 10, 200, 40);

    imagePreview.setBounds(getWidth() / 3 +20, 60, 128, 128);

    escLabel.setBounds(getWidth() / 3 + 20, 200, 150, 40);


    ContentLabel2.setBounds(getWidth() / 3 - 150, 280, 200, 40);
   webLinkButton.setBounds(getWidth() / 3 + 50, 280, 350, 48);

    ContentLabel3.setBounds(getWidth() / 3 - 150, 320, 200, 40);
   forumLinkButton.setBounds(getWidth() / 3 + 50, 320, 350, 48);




}

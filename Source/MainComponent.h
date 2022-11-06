#pragma once

#include <JuceHeader.h>
#include "AboutContent.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/

//struct myDialog : public DialogWindow::LaunchOptions
//{
//
//
//};


class MainComponent  : public juce::Component
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void showAboutButtonOnClick();
    void showAsyncAboutButtonClick();

    TextButton showAboutButton;
    TextButton showAsyncAboutButton;
    

private:
    //==============================================================================
    // Your private member variables go here...
    
    
    DialogWindow aboutBox;
    DialogWindow::LaunchOptions myDialog;

    // designer = 0 normal run, designer = 1, run about box ( if it = 0) instead of MainComponent (for placing the controls on the about box)
#define designer  1
#if designer == 0
    std::unique_ptr<AboutContent> mainWindow;
#else
    std::unique_ptr<MainComponent> mainWindow;
#endif
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)


};

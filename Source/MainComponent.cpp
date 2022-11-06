#include "MainComponent.h"
#include "AboutContent.h"

//  the WindowDialog uses a initializer list and is called like this.
MainComponent::MainComponent()  : aboutBox("About Box", juce::Desktop::getInstance().getDefaultLookAndFeel()
	.findColour(juce::ResizableWindow::backgroundColourId), true, true) 
{
    addAndMakeVisible(showAboutButton);
    showAboutButton.setButtonText("Show using old style");
    showAboutButton.onClick = [this] { showAboutButtonOnClick(); };

    addAndMakeVisible(showAsyncAboutButton);
    showAsyncAboutButton.setButtonText("Show using Async Call");
    showAsyncAboutButton.onClick = [this] { showAsyncAboutButtonClick(); };


    setSize (600, 400);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    //g.setFont (juce::Font (16.0f));
    //g.setColour (juce::Colours::white);
    //g.drawText ("Hello World!", getLocalBounds(), juce::Justification::centred, true);
}

void MainComponent::resized()
{
    showAboutButton.setBounds(getWidth() / 2 -150, getHeight() / 2 - 50, 120, 40);
    showAsyncAboutButton.setBounds(getWidth() / 2 - 10, getHeight() / 2 - 50, 120, 40);

}

void MainComponent::showAboutButtonOnClick()
{
// and the dialog is called like this..   
    AboutContent *pAboutBox;
    pAboutBox = new AboutContent();
    DialogWindow::showModalDialog("About called directly", pAboutBox, this, Colours::grey, true);
    delete pAboutBox;
   
}

// preferred way of calling the dialog
void MainComponent::showAsyncAboutButtonClick()
{
    DialogWindow::LaunchOptions launchOptions;
	AboutContent* ab = new AboutContent();


	launchOptions.dialogTitle = ("About Box with launchAsync - preferred way -");
	launchOptions.escapeKeyTriggersCloseButton = true;
	launchOptions.resizable = false;
	launchOptions.useNativeTitleBar = false;
	launchOptions.useBottomRightCornerResizer = true;
	launchOptions.componentToCentreAround = getParentComponent();
	launchOptions.content.setOwned(ab);
	launchOptions.content->setSize(600, 400);
	launchOptions.dialogBackgroundColour = LookAndFeel::getDefaultLookAndFeel().findColour(ResizableWindow::backgroundColourId);

    launchOptions.launchAsync();



}

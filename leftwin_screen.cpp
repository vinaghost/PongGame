#include "leftwin_screen.h"
#include "caption.h"
LeftWinScreen::LeftWinScreen(RenderWindow* window) : WinScreen(window) {
	continueMenu->addButtons("Play again");
	continueMenu->addButtons("Back to Mainmenu");
	continueMenu->initMenu(80);
}

LeftWinScreen::~LeftWinScreen() {
}
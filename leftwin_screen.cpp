#include "leftwin_screen.h"

LeftWinScreen::LeftWinScreen(RenderWindow* window) : WinScreen(window) {
	continueMenu->addButtons("Play again");
	continueMenu->addButtons("Back to Mainmenu");
	continueMenu->addButtons("Left Win");
	continueMenu->initMenu(80);
}

LeftWinScreen::~LeftWinScreen() {
}
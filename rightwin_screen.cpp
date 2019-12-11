#include "rightwin_screen.h"

RightWinScreen::RightWinScreen(RenderWindow* window) : WinScreen(window) {
	continueMenu->addButtons("Play again");
	continueMenu->addButtons("Back to Mainmenu");
	continueMenu->addButtons("Right Win");
	continueMenu->initMenu(80);
}

RightWinScreen::~RightWinScreen() {
}
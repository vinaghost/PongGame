#include "WindowPong.h"

int main()
{
	GamePong game(800,600,1);
	while (game.isOpenWindow()) {
		game.Run();
		game.reset();
	}
	return 0;
}
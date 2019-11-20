//include Thư viện

#include "game.h"

//include Thư viện

int main() {
	//Code test

	Game g(800, 600);


	while (g.isOpenWindow()) {
		g.run();
		g.reset();
	}

	//Code test
	return 0;
}
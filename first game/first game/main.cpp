#include "gameHandler.h"
#include <conio.h>
#include <thread>

#define WIDTH 1600
#define HEIGHT 900

int main(int argc, char** argv)
{
	GameHandler game(WIDTH, HEIGHT, "KrBr");

	thread render(&GameHandler::renderLoop, &game);
	thread audio(&GameHandler::audioLoop, &game);
	thread input(&GameHandler::inputLoop, &game);
	thread logic(&GameHandler::logicLoop, &game);

	while (game.GetRunningState())
	{
		SDL_Delay(100);
	}

	render.join();
	audio.join();
	input.join();
	logic.join();

	return 0;
}
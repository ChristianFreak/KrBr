#include "gameHandler.h"
#include <conio.h>

#define WIDTH 1280
#define HEIGHT 720

int main(int argc, char** argv)
{
	GameHandler game(1280, 720, "KrBr");
	
	_getch();
	return 0;
}
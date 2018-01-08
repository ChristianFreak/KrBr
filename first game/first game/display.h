#ifndef DISPLAY_H
#define DISPLAY_H

#include "GL\glew.h"
#include "SDL2\SDL.h"
#include <string>
#include <iostream>

using namespace std;

class Display
{

public:
	Display(int width, int height, const string& title);
	virtual ~Display();

	void Clear(float r, float g, float b, float a);
	void SwapBuffers();

protected:

private:
	SDL_Window* m_window;
	SDL_GLContext m_glContext;

};

#endif //!DISPLAY_H

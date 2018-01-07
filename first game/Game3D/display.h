#ifndef  DISPLAY_H
#define DISPLAY_H

#include "SDL2/SDL.h"
#include "GL/glew.h"
#include <string>
#include <iostream>

using namespace std;

class Display
{

public:
	Display(int width, int height, const string& title);
	virtual ~Display();

	void Clear(float r, float g, float b, float a);
	void Update();

	inline bool IsOpen() { return m_isOpen; }

protected:

private:
	SDL_Window* m_window;
	SDL_GLContext m_glContext;

	bool m_isOpen = false;

};

#endif // ! DISPLAY_H


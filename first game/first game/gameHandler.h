#ifndef GAMEHANDLER_H
#define GAMEHANDLER_H

#include "display.h"
#include "camera.h"
#include "renderCore.h"

using namespace std;

class GameHandler
{
public:
	GameHandler(int width, int height, string title);
	void Stop();
	void renderLoop();
	void audioLoop();
	void inputLoop();
	void logicLoop();

	inline bool GetRunningState() { return m_isRunning; }
private:
	bool m_isRunning = false;

	bool m_w = false;
	bool m_a = false;
	bool m_s = false;
	bool m_d = false;

	int m_width;
	int m_height;
	string m_title;

	Camera m_camera;
};

#endif // !GAMEHANDLER_H

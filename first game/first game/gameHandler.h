#ifndef GAMEHANDLER_H
#define GAMEHANDLER_H

#include <thread>

using namespace std;

class GameHandler
{
public:
	GameHandler(int width, int height, string title);
	void Stop();
private:
	void renderLoop();
	void audioLoop();
	void inputLoop();
	void logicLoop();

	thread m_renderT;
	thread m_audioT;
	thread m_inputT;
	thread m_logicT;

	bool isRunning;
};

#endif // !GAMEHANDLER_H

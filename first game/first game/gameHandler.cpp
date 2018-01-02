#include "gameHandler.h"

GameHandler::GameHandler(int width, int height, string title) : isRunning(true),
	m_renderT(&GameHandler::renderLoop, this), m_audioT(&GameHandler::audioLoop, this),
	m_inputT(&GameHandler::inputLoop, this),   m_logicT(&GameHandler::logicLoop, this)
{
}

void GameHandler::Stop()
{
	isRunning = false;
	m_renderT.join();
	m_audioT.join();
	m_inputT.join();
	m_logicT.join();
}

void GameHandler::renderLoop()
{
	while (isRunning)
	{
		//Render Work
	}
}

void GameHandler::audioLoop()
{
	while (isRunning)
	{
		//Audio Work
	}
}

void GameHandler::inputLoop()
{
	while (isRunning)
	{
		//Input Work
	}
}

void GameHandler::logicLoop()
{
	while (isRunning)
	{
		//Logic Work
	}
}

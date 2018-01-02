#include "gameHandler.h"

GameHandler::GameHandler(int width, int height, string title) :
	m_renderT(&GameHandler::renderLoop, this), m_audioT(&GameHandler::audioLoop, this),
	m_inputT(&GameHandler::inputLoop, this),   m_logicT(&GameHandler::logicLoop, this)
{

}

void GameHandler::Start()
{
	m_renderT.join();
	m_audioT.join();
	m_inputT.join();
	m_logicT.join();
}

void GameHandler::Kill()
{
	m_renderT.~thread();
	m_audioT.~thread();
	m_inputT.~thread();
	m_logicT.~thread();
}

void GameHandler::renderLoop()
{
	while (1)
	{
		printf("test1");
	}
}

void GameHandler::audioLoop()
{
	while (1)
	{
		printf("test2");
	}
}

void GameHandler::inputLoop()
{
	while (1)
	{
		printf("test3");
	}
}

void GameHandler::logicLoop()
{
	while (1)
	{
		printf("test4");
	}
}

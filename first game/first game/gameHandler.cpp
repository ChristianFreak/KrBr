#include "gameHandler.h"

GameHandler::GameHandler(int width, int height, string title) :
	m_camera(glm::vec3(0.0f, 0.0f, -5.0f), 70.0f, (float)width / (float)height, 0.1f, 100.0f)
{
	m_width = width;
	m_height = height;
	m_title = title;

	m_isRunning = true;
}

void GameHandler::Stop()
{
	m_isRunning = false;
}

void GameHandler::renderLoop()
{
	Display display(m_width, m_height, m_title);
	RenderCore render(".\\shaders\\basicShader", m_camera);

	RenderTarget target(".\\tex\\tex_02.jpg", ".\\tex\\monkey3.obj");
	render.AddTarget(target);

	float counter = 0.0f;
	int oldX, oldY, newX, newY;
	bool firstStart = true;

	SDL_Event e;

	while (m_isRunning)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				GameHandler::Stop();
			}
			if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_w:
					m_w = true;
					break;
				case SDLK_a:
					m_a = true;
					break;
				case SDLK_s:
					m_s = true;
					break;
				case SDLK_d:
					m_d = true;
					break;
				default:
					break;
				}
			}
			if (e.type == SDL_KEYUP)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_w:
					m_w = false;
					break;
				case SDLK_a:
					m_a = false;
					break;
				case SDLK_s:
					m_s = false;
					break;
				case SDLK_d:
					m_d = false;
					break;
				default:
					break;
				}
			}
			if (e.type == SDL_MOUSEMOTION)
			{
				newX = e.button.x;
				newY = e.button.y;

				if (firstStart)
				{
					oldX = newX;
					oldY = newY;
					firstStart = false;
				}
				else
				{
					if (newX < oldX)
					{
						m_camera.RotateY(0.05f);
					}
					else if (newX > oldX)
					{
						m_camera.RotateY(-0.05f);
					}

					if (newY < oldY)
					{
						m_camera.Pitch(-0.05f);
					}
					else if (newY > oldY)
					{
						m_camera.Pitch(0.05f);
					}

					oldX = newX;
					oldY = newY;
				}
			}
		}

	    display.Clear(0.0f, 0.0f, 0.0f, 1.0f);
		target.GetTransform()->GetRot()->y = counter;
		render.RenderTargets();
		display.SwapBuffers();
		counter += 0.01;
		SDL_Delay(10);
	}
}

void GameHandler::inputLoop()
{
	m_camera.SetFlying(false);

	while (m_isRunning)
	{
		if (m_w)
		{
			m_camera.MoveForward(0.1f);
		}
		if (m_a)
		{
			m_camera.MoveRight(-0.1f);
		}
		if (m_s)
		{
			m_camera.MoveForward(-0.1f);
		}
		if (m_d)
		{
			m_camera.MoveRight(0.1f);
		}
		SDL_Delay(10);
	}
}

void GameHandler::audioLoop()
{
	while (m_isRunning)
	{
		
	}
}

void GameHandler::logicLoop()
{
	while (m_isRunning)
	{
		
	}
}

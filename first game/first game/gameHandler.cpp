#include "gameHandler.h"

GameHandler::GameHandler(int width, int height, string title) 
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

	Camera pCam(glm::vec3(0.0f, 2.0f, -5.0f), 70.0f, (float)m_width / (float)m_height, 0.1f, 100.0f);

	Vertex pVertices[] =
	{
		Vertex(glm::vec3(-1, -1, -1), glm::vec2(1, 0), glm::vec3(0, 0, -1)),
		Vertex(glm::vec3(-1, 1, -1), glm::vec2(0, 0), glm::vec3(0, 0, -1)),
		Vertex(glm::vec3(1, 1, -1), glm::vec2(0, 1), glm::vec3(0, 0, -1)),
		Vertex(glm::vec3(1, -1, -1), glm::vec2(1, 1), glm::vec3(0, 0, -1)),

		Vertex(glm::vec3(-1, -1, 1), glm::vec2(1, 0), glm::vec3(0, 0, 1)),
		Vertex(glm::vec3(-1, 1, 1), glm::vec2(0, 0), glm::vec3(0, 0, 1)),
		Vertex(glm::vec3(1, 1, 1), glm::vec2(0, 1), glm::vec3(0, 0, 1)),
		Vertex(glm::vec3(1, -1, 1), glm::vec2(1, 1), glm::vec3(0, 0, 1)),

		Vertex(glm::vec3(-1, -1, -1), glm::vec2(0, 1), glm::vec3(0, -1, 0)),
		Vertex(glm::vec3(-1, -1, 1), glm::vec2(1, 1), glm::vec3(0, -1, 0)),
		Vertex(glm::vec3(1, -1, 1), glm::vec2(1, 0), glm::vec3(0, -1, 0)),
		Vertex(glm::vec3(1, -1, -1), glm::vec2(0, 0), glm::vec3(0, -1, 0)),

		Vertex(glm::vec3(-1, 1, -1), glm::vec2(0, 1), glm::vec3(0, 1, 0)),
		Vertex(glm::vec3(-1, 1, 1), glm::vec2(1, 1), glm::vec3(0, 1, 0)),
		Vertex(glm::vec3(1, 1, 1), glm::vec2(1, 0), glm::vec3(0, 1, 0)),
		Vertex(glm::vec3(1, 1, -1), glm::vec2(0, 0), glm::vec3(0, 1, 0)),

		Vertex(glm::vec3(-1, -1, -1), glm::vec2(1, 1), glm::vec3(-1, 0, 0)),
		Vertex(glm::vec3(-1, -1, 1), glm::vec2(1, 0), glm::vec3(-1, 0, 0)),
		Vertex(glm::vec3(-1, 1, 1), glm::vec2(0, 0), glm::vec3(-1, 0, 0)),
		Vertex(glm::vec3(-1, 1, -1), glm::vec2(0, 1), glm::vec3(-1, 0, 0)),

		Vertex(glm::vec3(1, -1, -1), glm::vec2(1, 1), glm::vec3(1, 0, 0)),
		Vertex(glm::vec3(1, -1, 1), glm::vec2(1, 0), glm::vec3(1, 0, 0)),
		Vertex(glm::vec3(1, 1, 1), glm::vec2(0, 0), glm::vec3(1, 0, 0)),
		Vertex(glm::vec3(1, 1, -1), glm::vec2(0, 1), glm::vec3(1, 0, 0)),
	};
	unsigned int pIndices[] = { 0, 1, 2,
		0, 2, 3,

		6, 5, 4,
		7, 6, 4,

		10, 9, 8,
		11, 10, 8,

		12, 13, 14,
		12, 14, 15,

		16, 17, 18,
		16, 18, 19,

		22, 21, 20,
		23, 22, 20
	};

	Vertex front[] =
	{
		Vertex(glm::vec3(-20, -5, 0), glm::vec2(1, 0), glm::vec3(0, 0, -1)),
		Vertex(glm::vec3(-20, 5, 0), glm::vec2(0, 0), glm::vec3(0, 0, -1)),
		Vertex(glm::vec3(20, 5, 0), glm::vec2(0, 1), glm::vec3(0, 0, -1)),
		Vertex(glm::vec3(20, -5, 0), glm::vec2(1, 1), glm::vec3(0, 0, -1)),
	};
	Vertex left[] =
	{
		Vertex(glm::vec3(20, -5, -20), glm::vec2(1, 1), glm::vec3(0, 0, -1)),
		Vertex(glm::vec3(20, -5, 20), glm::vec2(1, 0), glm::vec3(0, 0, -1)),
		Vertex(glm::vec3(20, 5, 20), glm::vec2(0, 0), glm::vec3(0, 0, -1)),
		Vertex(glm::vec3(20, 5, -20), glm::vec2(0, 1), glm::vec3(0, 0, -1)),
	};
	Vertex floor[] =
	{
		Vertex(glm::vec3(-20, -5, -20), glm::vec2(0, 1), glm::vec3(0, 0, -1)),
		Vertex(glm::vec3(-20, -5, 20), glm::vec2(1, 1), glm::vec3(0, 0, -1)),
		Vertex(glm::vec3(20, -5, 20), glm::vec2(1, 0), glm::vec3(0, 0, -1)),
		Vertex(glm::vec3(20, -5, -20), glm::vec2(0, 0), glm::vec3(0, 0, -1)),
	};

	unsigned int indices[] = { 0, 1, 2, 0, 2, 3 };
	
	RenderCore render(".\\shaders\\basicShader", pCam);
	RenderTarget wall1(".\\tex\\tex_02.jpg", front, sizeof(front) / sizeof(front[0]), indices, sizeof(indices) / sizeof(indices[0]));
	RenderTarget wall2(".\\tex\\tex_02.jpg", left, sizeof(left) / sizeof(left[0]), indices, sizeof(indices) / sizeof(indices[0]));
	RenderTarget wall3(".\\tex\\tex_03.png", floor, sizeof(floor) / sizeof(floor[0]), indices, sizeof(indices) / sizeof(indices[0]));
	RenderTarget pTarget(".\\tex\\tex_02.jpg", pVertices, sizeof(pVertices) / sizeof(pVertices[0]), pIndices, sizeof(pIndices) / sizeof(pIndices[0]));

	m_player = Player(pCam, pTarget, 5);

	render.AddTarget(wall1);
	render.AddTarget(wall2);
	render.AddTarget(wall3);
	render.AddTarget(pTarget);

	m_playerInitialized = true;

	wall2.GetTransform()->GetPos()->z -= 20;
	wall3.GetTransform()->GetPos()->z -= 20;

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
				case SDLK_ESCAPE:
					GameHandler::Stop();
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
						m_player.RotateY(0.025f);
					}
					else if (newX > oldX)
					{
						m_player.RotateY(-0.025f);
					}

					if (newY < oldY)
					{
						m_player.Pitch(-0.025f);
					}
					else if (newY > oldY)
					{
						m_player.Pitch(0.025f);
					}

					oldX = newX;
					oldY = newY;
				}
			}
		}

	    display.Clear(0.0f, 0.0f, 0.0f, 1.0f);
		render.RenderTargets();
		display.SwapBuffers();
		counter += 0.01;
		SDL_Delay(10);
	}
}

void GameHandler::inputLoop()
{
	while (!m_playerInitialized)
	{
		SDL_Delay(5);
	}

	m_player.SetFlying(false);

	while (m_isRunning)
	{
		if (m_w)
		{
			m_player.MoveForward(0.1f);
		}
		if (m_a)
		{
			m_player.MoveRight(-0.1f);
		}
		if (m_s)
		{
			m_player.MoveForward(-0.1f);
		}
		if (m_d)
		{
			m_player.MoveRight(0.1f);
		}
		SDL_Delay(10);
	}
}

void GameHandler::audioLoop()
{
	while (m_isRunning)
	{
		SDL_Delay(5);
	}
}

void GameHandler::logicLoop()
{
	while (m_isRunning)
	{
		SDL_Delay(5);
	}
}

void GameHandler::gravityLoop()
{
	while (!m_playerInitialized)
	{
		SDL_Delay(5);
	}

	float *y = m_player.GetY();

	while (m_isRunning)
	{
		while ((*y > -4.5) && (!(m_player.GetFlying())))
		{
			m_player.SetY(*y - 0.01);
			SDL_Delay(5);
		}
		SDL_Delay(5);
	}
}

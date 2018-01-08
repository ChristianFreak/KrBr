#include <iostream>
#include <SDL2/SDL.h>
#include "display.h"
#include "mesh.h"
#include "shader.h"
#include "texture.h"
#include "transform.h"
#include "camera.h"

static const int DISPLAY_WIDTH = 800;
static const int DISPLAY_HEIGHT = 600;

int main(int argc, char** argv)
{
	Display display(DISPLAY_WIDTH, DISPLAY_HEIGHT, "OpenGL");
	 
	Vertex vertices[] = 
	{
		Vertex(-1, 0.6f,-1,  1, 0,  0, 0, -1),
		Vertex(-1, 0.3f, 1,  0, 0,  0, 0, -1),
		Vertex( 1, 0.1f, 1,  0, 1,  0, 0, -1),
		Vertex( 1, 0.3f,-1,  1, 1,  0, 0, -1),
	};

	unsigned int indices[] = { 0, 1, 2, 0, 2, 3 };

	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]), indices, sizeof(indices) / sizeof(indices[0]));
	Shader shader(".\\shaders\\basicShader");
	Texture texture(".\\textures\\tex_02.png");
	Transform transform;

	Camera camera(glm::vec3(0.0f, 2.0f, -5.0f), 70.0f, (float)DISPLAY_WIDTH / (float)DISPLAY_HEIGHT, 0.1f, 100.0f);

	SDL_Event e;
	bool isRunning = true;

	while (isRunning)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				isRunning = false;
			}
			if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_w:
					camera.MoveForward(0.1f);
					break;
				case SDLK_a:
					camera.MoveRight(-0.1f);
					break;
				case SDLK_s:
					camera.MoveForward(-0.1f);
					break;
				case SDLK_d:
					camera.MoveRight(0.1f);
					break;
				case SDLK_UP:
					camera.Pitch(-0.05);
					break;
				case SDLK_DOWN:
					camera.Pitch(0.05);
					break;
				case SDLK_LEFT:
					camera.RotateY(0.05);
					break;
				case SDLK_RIGHT:
					camera.RotateY(-0.05);
					break;
				}
			}
		}

		display.Clear(0.0f, 0.0f, 0.0f, 1.0f);

		shader.Bind();
		texture.Bind();
		shader.Update(transform, camera);
		mesh.Draw();

		display.SwapBuffers();
		SDL_Delay(1);
	}

	return 0;
}
#include "display.h"
#include "shader.h"
#include "camera.h"
#include "transform.h"
#include "mesh.h"
#include "texture.h"
#include "block.h";

#define WIDTH 1280
#define HEIGHT 720

int main(int argc, char** argv)
{
	Display display(WIDTH, HEIGHT, "KrBr");

	glm::vec3 startViewpoint = glm::vec3(0.0f, 4.0f, -5.0f);
	float aspectRatio = (float)WIDTH / (float)HEIGHT;
	float zNear = 0.1f, zFar = 100.0f, fov = 100.0f;

	Shader shader(".\\shaders\\basicShader");
	Camera camera(startViewpoint, fov, aspectRatio, zNear, zFar);
	Block block(".\\tex\\tex_03.png", 0);

	SDL_Event e;
	bool isRunning = true;

	while (isRunning)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
				isRunning = false;
			if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_w:
					camera.MoveForward(0.05f);
					break;
				case SDLK_s:
					camera.MoveForward(-0.05f);
					break;
				case SDLK_d:
					camera.MoveRight(-0.05f);
					break;
				case SDLK_a:
					camera.MoveRight(0.05f);
					break;
				case SDLK_SPACE:
					camera.GetPosition()->y -= 0.05f;
					break;
				case SDLK_LSHIFT:
					camera.GetPosition()->y += 0.05f;
					break;
				case SDLK_ESCAPE:
					isRunning = false;
					break;
				case SDLK_RIGHT:
					camera.RotateY(0.05);
					break;
				case SDLK_LEFT:
					camera.RotateY(-0.05);
					break;
				case SDLK_UP:
					camera.Pitch(0.05);
					break;
				case SDLK_DOWN:
					camera.Pitch(-0.05);
					break;
				}
			}
		}

		display.Clear(0.0f, 0.0f, 0.0f, 1.0f);

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				block.GetTransform()->SetPos(glm::vec3(i * 2.0f, 0, j * 2.0f));
				block.DrawBlock(shader, camera);
			}
		}

		display.SwapBuffers();
		SDL_Delay(1);
	}

	return 0;
}
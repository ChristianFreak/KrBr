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

	Mesh monkey(".\\models\\monkey3.obj");
	Shader shader(".\\shaders\\basicShader");
	Texture texture(".\\textures\\tex_02.png");
	Transform transform;
	Camera camera(glm::vec3(0.0f, 0.0f, -5.0f), 70.0f, (float)DISPLAY_WIDTH / (float)DISPLAY_HEIGHT, 0.1f, 100.0f);

	SDL_Event e;
	bool isRunning = true;
	float counter = 0.0f;
	while (isRunning)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				isRunning = false;
			}
		}

		display.Clear(0.0f, 0.0f, 0.0f, 1.0f);

		shader.Bind();
		texture.Bind();
		shader.Update(transform, camera);
		monkey.Draw();

		display.SwapBuffers();
		SDL_Delay(1);
		counter += 0.0001f;
	}

	return 0;
}
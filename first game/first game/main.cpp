#include "display.h"
#include "shader.h"
#include "camera.h"
#include "transform.h"
#include "mesh.h"
#include "texture.h"

#define WIDTH 1280
#define HEIGHT 720

int main(int argc, char** argv)
{
	Display display(WIDTH, HEIGHT, "KrBr");

	glm::vec3 startViewpoint = glm::vec3(0.0f, 0.0f, -5.0f);
	float aspectRatio = (float)WIDTH / (float)HEIGHT;
	float zNear = 0.1f, zFar = 100.0f, fov = 90.0f;

	Vertex vertices[] =
	{
		Vertex(glm::vec3(-1, -1, -1), glm::vec2(1, 0), glm::vec3(0, 0, -1)),
		Vertex(glm::vec3(-1, 1, -1), glm::vec2(0, 0), glm::vec3(0, 0, -1)),
		Vertex(glm::vec3(1, 1, -1), glm::vec2(0, 1), glm::vec3(0, 0, -1)),
	};

	unsigned int indices[] = { 0, 1, 3};

	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]), indices, sizeof(indices) / sizeof(indices[0]));
	Mesh monkey(".\\tex\\monkey3.obj");
	Shader shader(".\\shaders\\basicShader");
	Texture texture(".\\tex\\tex_02.jpg");
	Transform transform;
	Camera camera(startViewpoint, fov, aspectRatio, zNear, zFar);

	SDL_Event e;
	bool isRunning = true;

	while (isRunning)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
				isRunning = false;
		}

		display.Clear(0.0f, 0.0f, 0.0f, 1.0f);

		shader.Bind();
		texture.Bind();
		shader.Update(transform, camera);
		monkey.Draw();

		display.SwapBuffers();
		SDL_Delay(1);
	}

	return 0;
}
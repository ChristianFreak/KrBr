#include <iostream>
#include "display.h"
#include "shader.h"
#include "mesh.h"
#include "texture.h"
#include "camera.h"

int main(int argc, char** argv)
{
	Display display(800, 600, "Game2D");
	Shader shader(".\\shaders\\basicShader");

	Vertex vertices[] =
	{
		Vertex( 0.0f, 0.0f, 0.0f, 0.0f, 1.0f),
		Vertex( 0.0f, 0.5f, 0.0f, 0.0f, 0.0f),
		Vertex( 0.5f, 0.0f, 0.0f, 1.0f, 0.0f),
	};

	unsigned int indices[] = { 0, 1, 2 };

	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]), indices, sizeof(indices) / sizeof(indices[0]));
	Mesh mesh2(".\\models\\monkey3.obj");
	Texture texture(".\\textures\\tex_02.png");
	Camera camera(vec3(0.0f, 0.0f, -3.0f), 70.0f, 800.0f / 600.0f, 0.01f, 1000.0f);
	Transform transform;

	float counter = 0.0f;

	while (display.IsOpen())
	{
		display.Clear(0, 0, 0.15f, 0);

		shader.Bind();
		texture.Bind(0);
		shader.Update(transform, camera);
		mesh2.Draw();

		display.Update();
	}

	return 0;
}
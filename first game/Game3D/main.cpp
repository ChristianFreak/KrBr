#include <iostream>
#include "display.h"
#include "shader.h"
#include "mesh.h"
#include "texture.h"

int main(int argc, char** argv)
{
	Display display(800, 600, "Game2D");
	Shader shader(".\\shaders\\basicShader");

	Vertex vertices[] =
	{
		Vertex( 0.0f, 0.5f, 0.0f, 0.5f, 1.0f),
		Vertex(-0.5f,-0.5f, 0.0f, 0.0f, 0.0f),
		Vertex( 0.5f,-0.5f, 0.0f, 1.0f, 0.0f),
	};

	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));
	Texture texture(".\\textures\\tex_02.png");

	while (display.IsOpen())
	{
		display.Clear(0, 0, 0.15f, 0);
		shader.Bind();
		texture.Bind(0);
		mesh.Draw();
		display.Update();
	}


	return 0;
}
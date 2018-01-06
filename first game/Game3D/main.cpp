#include <iostream>
#include "display.h"
#include "shader.h"
#include "mesh.h"

int main(int argc, char** argv)
{
	Display display(800, 600, "Game2D");
	Shader shader(".\\shaders\\basicShader");

	Vertex vertices[] =
	{
		Vertex(-1, 0, 0),
		Vertex(-1,-1, 0),
		Vertex( 1, 0, 0),
	};

	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));

	while (display.IsOpen())
	{
		display.Clear(0, 0, 0, 0);
		shader.Bind();
		mesh.Draw();
		display.Update();
	}

	return 0;
}
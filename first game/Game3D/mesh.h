#ifndef MESH_H
#define MESH_H

#include "vertex.h"
#include "GL/glew.h"
#include <iostream>

using namespace std;

class Mesh
{

public:
	Mesh(Vertex* vertices, unsigned int numVertices);
	virtual ~Mesh();

	void Draw();

protected:

private:
	enum
	{
		POSITION_VB,
		NUM_BUFFERS
	};

	GLuint m_vertexArrayObject;
	GLuint m_vertexArrayBuffers[NUM_BUFFERS];

	unsigned int m_drawCount;

};

#endif // !MESH_H

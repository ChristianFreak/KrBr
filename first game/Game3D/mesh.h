#ifndef MESH_H
#define MESH_H

#include "vertex.h"
#include "GL/glew.h"
#include "obj_loader.h"
#include <iostream>
#include <vector>

using namespace std;

class Mesh
{

public:
	Mesh(Vertex* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices);
	Mesh(const std::string& objectFilePath);
	virtual ~Mesh();

	void Draw();

protected:

private:
	void InitMesh(const IndexedModel& model);

	enum
	{
		POSITION_VB,
		TEXCOORD_VB,

		INDEX_VB,

		NUM_BUFFERS
	};

	GLuint m_vertexArrayObject;
	GLuint m_vertexArrayBuffers[NUM_BUFFERS];

	unsigned int m_drawCount;

};

#endif // !MESH_H

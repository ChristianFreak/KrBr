#ifndef MESH_H
#define MESH_H

#include <GL/glew.h>
#include "obj_loader.h"
#include "vertex.h"
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

enum MeshBufferPositions
{
	POSITION_VB,
	TEXCOORD_VB,
	NORMAL_VB,
	INDEX_VB
};

class Mesh
{
public:
    Mesh(const string& fileName);
	Mesh(Vertex* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices);
	virtual ~Mesh();

	void Draw();

protected:

private:
	void InitMesh(const IndexedModel& model);

	static const unsigned int NUM_BUFFERS = 4;

	GLuint m_vertexArrayObject;
	GLuint m_vertexArrayBuffers[NUM_BUFFERS];

	unsigned int m_numIndices;

};

#endif //!MESH_H

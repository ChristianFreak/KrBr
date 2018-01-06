#ifndef VERTEX_H
#define VERTEX_H

#include <glm/glm.hpp>

using namespace glm;

class Vertex
{

public:
	Vertex(float x, float y, float z)
	{
		m_position = vec3(x, y, z);
	}

protected:

private:
	vec3 m_position;

};

#endif // !VERTEX_H


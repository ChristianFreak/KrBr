#ifndef VERTEX_H
#define VERTEX_H

#include <glm/glm.hpp>

using namespace glm;

class Vertex
{

public:
	Vertex(float x, float y, float z, float tX, float tY)
	{
		m_position = vec3(x, y, z);
		m_texCoord = vec2(tX, tY);
	}

	inline glm::vec3* GetPosition() { return &m_position; }
	inline glm::vec2* GetTexCoord() { return &m_texCoord; }

protected:

private:
	vec3 m_position;
	vec2 m_texCoord;

};

#endif // !VERTEX_H


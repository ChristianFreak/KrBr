#ifndef VERTEX_H
#define VERTEXT_H

#include "glm\glm.hpp"

using namespace glm;

struct Vertex
{

public:
	Vertex(float x, float y, float z, float tX, float tY, float nX, float nY, float nZ)
	{
		m_position = vec3(x, y, z);
		m_texCoord = vec2(tX, tY);
		m_normal   = vec3(nX, nY, nZ);
	}

	vec3* GetPosition() { return &m_position; }
	vec2* GetTexCoord() { return &m_texCoord; }
	vec3* GetNormal  () { return &m_normal  ; }

protected:

private:
	vec3 m_position;
	vec2 m_texCoord;
	vec3 m_normal;

};

#endif // !VERTEX_H

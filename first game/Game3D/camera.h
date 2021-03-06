#ifndef CAMERA_H
#define CAMERA_H

#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"

using namespace glm;

class Camera
{

public:
	Camera(const vec3& pos, float fov, float aspect, float zNear, float zFar)
	{
		m_perspective = perspective(fov, aspect, zNear, zFar);
		m_position = pos;
		m_forward = vec3(0.0f, 0.0f, 1.0f);
		m_up = vec3(0.0f, 1.0f, 0.0f);
	}

	inline mat4 GetViewProjection() const
	{
		return m_perspective * lookAt(m_position, m_position + m_forward, m_up);
	}

protected:

private:
	mat4 m_perspective;
	vec3 m_position;
	vec3 m_forward;
	vec3 m_up;

};

#endif // !CAMERA_H

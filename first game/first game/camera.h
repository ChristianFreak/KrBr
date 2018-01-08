#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/transform.hpp>

using namespace glm;

struct Camera
{

public:
	Camera(const vec3& pos, float fov, float aspect, float zNear, float zFar)
	{
		m_position = pos;
		m_forward    = vec3(0.0f, 0.0f, 1.0f);
		m_up		 = vec3(0.0f, 1.0f, 0.0f);
		m_projection = perspective(fov, aspect, zNear, zFar);
	}

	inline mat4 GetViewProjection() const
	{
		return m_projection * lookAt(m_position, m_position + m_forward, m_up);
	}

	void MoveForward(float amt)
	{
		m_position += m_forward * amt;
	}

	void MoveRight(float amt)
	{
		m_position -= cross(m_up, m_forward) * amt;
	}

	void Pitch(float angle)
	{
		vec3 right = normalize(cross(m_up, m_forward));

		m_forward = vec3(normalize(rotate(angle, right) * vec4(m_forward, 0.0)));
		m_up = normalize(cross(m_forward, right));
	}

	void RotateY(float angle)
	{
		static const vec3 UP(0.0f, 1.0f, 0.0f);

		mat4 rotation = rotate(angle, UP);

		m_forward = vec3(normalize(rotation * vec4(m_forward, 0.0)));
		m_up = vec3(normalize(rotation * vec4(m_up, 0.0)));
	}

protected:

private:
	mat4 m_projection;
	vec3 m_position;
	vec3 m_forward;
	vec3 m_up;

};

#endif //!CAMERA_H
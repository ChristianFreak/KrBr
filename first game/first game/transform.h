#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "camera.h"
#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/transform.hpp>

using namespace glm;

struct Transform
{

public:
	Transform(const vec3& pos, const vec3& rot, const vec3& scale)
	{
		m_position = pos  ;
		m_rotation = rot  ;
		m_scale    = scale;
	}
	Transform()
	{
		m_position = vec3();
		m_rotation = vec3();
		m_scale    = vec3(1.0f, 1.0f, 1.0f);
	}

	inline mat4 GetModel() const
	{
		mat4 posMat = translate(m_position);
		mat4 scaleMat = scale(m_scale);

		mat4 rotX = rotate(m_rotation.x, vec3(1.0, 0.0, 0.0));
		mat4 rotY = rotate(m_rotation.y, vec3(0.0, 1.0, 0.0));
		mat4 rotZ = rotate(m_rotation.z, vec3(0.0, 0.0, 1.0));

		mat4 rotMat = rotX * rotY * rotZ;

		return posMat * rotMat * scaleMat;
	}

	inline mat4 GetMVP(const Camera& camera) const
	{
		mat4 VP = camera.GetViewProjection();
		mat4 M = GetModel();

		return VP * M;
	}

	inline vec3* GetPosition() { return &m_position; }
	inline vec3* GetRotation() { return &m_rotation; }
	inline vec3* GetScale   () { return &m_scale   ; }

	inline void SetPosition(vec3& position) { m_position = position; }
	inline void SetRotation(vec3& rotation) { m_rotation = rotation; }
	inline void SetScale   (vec3& scale)    { m_scale    = scale   ; }

protected:

private:
	vec3 m_position;
	vec3 m_rotation;
	vec3 m_scale;

};

#endif //!TRANSFORM_H
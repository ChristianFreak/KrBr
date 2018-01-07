#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "glm/glm.hpp"
#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/transform.hpp"

using namespace glm;

class Transform
{

public:
	Transform()
	{
		m_position = vec3();
		m_rotation = vec3();
		m_scale = vec3(1.0f, 1.0f, 1.0f);
	}
	Transform(const vec3& pos, const vec3& rot, const vec3& scale)
	{
		m_position = pos;
		m_rotation = rot;
		m_scale = scale;
	}

	inline mat4 GetModel() const
	{
		mat4 posMatrix = translate(m_position);
		mat4 scaleMatrix = scale(m_scale);

		mat4 rotXMatrix = rotate(m_rotation.x, vec3(1.0f, 0.0f, 0.0f));
		mat4 rotYMatrix = rotate(m_rotation.y, vec3(0.0f, 1.0f, 0.0f));
		mat4 rotZMatrix = rotate(m_rotation.z, vec3(0.0f, 0.0f, 1.0f));

		mat4 rotMatrix = rotZMatrix * rotYMatrix * rotXMatrix;

		return posMatrix * rotMatrix * scaleMatrix;
	}

	inline vec3& GetPosition() { return m_position; }
	inline vec3& GetRotation() { return m_rotation; }
	inline vec3& GetScale   () { return m_scale;    }

	inline void SetPosition(const vec3& pos)   { m_position = pos;    }
	inline void SetRotation(const vec3& rot)   { m_rotation = rot;    }
	inline void SetScale   (const vec3& scale) { m_scale    = scale;  }

protected:

private:
	vec3 m_position;
	vec3 m_rotation;
	vec3 m_scale;

};

#endif // !TRANSFORM_H
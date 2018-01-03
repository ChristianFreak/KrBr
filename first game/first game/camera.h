#ifndef CAMERA_INCLUDED_H
#define CAMERA_INCLUDED_H

#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/transform.hpp>

struct Camera
{
public:
	Camera(const glm::vec3& pos, float fov, float aspect, float zNear, float zFar)
	{
		this->pos = pos;
		this->forward = glm::vec3(0.0f, 0.0f, 1.0f);
		this->change = glm::vec3(0.0f, 0.0f, 1.0f);
		this->up = glm::vec3(0.0f, 1.0f, 0.0f);
		this->projection = glm::perspective(fov, aspect, zNear, zFar);
	}

	inline glm::mat4 GetViewProjection() const
	{
		return projection * glm::lookAt(pos, pos + change, up);
	}

	inline glm::vec3* GetPosition() { return &pos; }

	void MoveForward(float amt)
	{
		pos += forward * amt;
	}

	void MoveRight(float amt)
	{
		pos -= glm::cross(up, forward) * amt;
	}

	void Pitch(float angle)
	{
		glm::vec3 right = glm::normalize(glm::cross(up, change));

		change = glm::vec3(glm::normalize(glm::rotate(angle, right) * glm::vec4(change, 0.0)));
		forward.x = change.x;
		forward.z = change.z;
		if (isFlying)
		{
			forward.y = change.y;
		}
		else
		{
			forward.y = 0;
		}
		up = glm::normalize(glm::cross(change, right));
	}

	void RotateY(float angle)
	{
		static const glm::vec3 UP(0.0f, 1.0f, 0.0f);

		glm::mat4 rotation = glm::rotate(angle, UP);

		change = glm::vec3(glm::normalize(rotation * glm::vec4(change, 0.0)));
		forward.x = change.x;
		forward.z = change.z;
		up = glm::vec3(glm::normalize(rotation * glm::vec4(up, 0.0)));
	}

	inline void SetFlying(bool state) { isFlying = state; }

protected:
private:
	glm::mat4 projection;
	glm::vec3 pos;
	glm::vec3 forward;
	glm::vec3 up;
	glm::vec3 change;
	bool isFlying;
};

#endif

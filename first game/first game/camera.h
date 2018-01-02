#ifndef CAMERA_INCLUDED_H
#define CAMERA_INCLUDED_H

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

struct Camera
{
public:
	Camera(const glm::vec3& pos, float fov, float aspect, float zNear, float zFar)
	{
		this->pos = pos;
		this->rotate = glm::vec3(0.0f, 0.0f, 1.0f);
		this->up = glm::vec3(0.0f, 1.0f, 0.0f);
		this->projection = glm::perspective(fov, aspect, zNear, zFar);
	}

	inline glm::mat4 GetViewProjection() const
	{
		return projection * glm::lookAt(pos, pos + rotate, up);
	}

	inline glm::vec3* GetPosition() { return &pos; }

	void MoveForward(float amt)
	{
		pos += glm::vec3(0.0f, 0.0f, 1.0f) * amt;
	}

	void MoveRight(float amt)
	{
		pos -= glm::cross(up, glm::vec3(0.0f, 0.0f, 1.0f)) * amt;
	}

	void Pitch(float angle)
	{
		glm::vec3 right = glm::normalize(glm::cross(up, rotate));

		rotate = glm::vec3(glm::normalize(glm::rotate(angle, right) * glm::vec4(rotate, 0.0)));
		up = glm::normalize(glm::cross(rotate, right));
	}

	void RotateY(float angle)
	{
		static const glm::vec3 UP(0.0f, 1.0f, 0.0f);

		glm::mat4 rotation = glm::rotate(angle, UP);

		rotate = glm::vec3(glm::normalize(rotation * glm::vec4(rotate, 0.0)));
		up = glm::vec3(glm::normalize(rotation * glm::vec4(up, 0.0)));
	}

protected:
private:
	glm::mat4 projection;
	glm::vec3 pos;
	glm::vec3 rotate;
	glm::vec3 up;
};

#endif

#ifndef MOVE_H
#define MOVE_H

#include <glm\glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/transform.hpp>

class Move
{
public:
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
	inline void SetPos(glm::vec3 pos) { this->pos = pos; }
	inline void SetForward(glm::vec3 forward) { this->forward = forward; }
	inline void SetUp(glm::vec3 up) { this->up = up; }
	inline void SetChange(glm::vec3 change) { this->change = change; }

	inline bool GetFlying() { return isFlying; }
	inline glm::vec3* GetPos() { return &pos; }
	inline glm::vec3 GetPosConst() const { return pos; }
	inline glm::vec3* GetForward() { return &forward; }
	inline glm::vec3* GetUp() { return &up; }
	inline glm::vec3* GetChange() { return &change; }
	inline glm::mat4 GetView() const { return glm::lookAt(pos, pos + change, up); }
private:
	glm::vec3 pos;
	glm::vec3 forward;
	glm::vec3 up;
	glm::vec3 change;
	bool isFlying;
};

#endif // !MOVE_H


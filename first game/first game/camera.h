#ifndef CAMERA_INCLUDED_H
#define CAMERA_INCLUDED_H

#include "move.h"

struct Camera : public Move
{
public:
	Camera(const glm::vec3& pos, float fov, float aspect, float zNear, float zFar)
	{
		SetPos(pos);
		SetForward(glm::vec3(0.0f, 0.0f, 1.0f));
		SetChange(glm::vec3(0.0f, 0.0f, 1.0f));
		SetUp(glm::vec3(0.0f, 1.0f, 0.0f));
		projection = glm::perspective(fov, aspect, zNear, zFar);
	}

	inline glm::mat4 GetViewProjection() const
	{
		return projection * GetView();
	}
protected:
private:
	glm::mat4 projection;
};

#endif

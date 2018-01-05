#ifndef PLAYER_H
#define PLAYER_H

#include "renderTarget.h"
#include "camera.h"

class Player
{
public:
	Player(Camera &camera, RenderTarget &renderTarget, float offset) :
		m_camera(&camera),
		m_renderTarget(&renderTarget)
	{
		m_offset = offset;

		m_renderTarget->GetTransform()->SetPos(glm::vec3(camera.GetPos()->x, camera.GetPos()->y, camera.GetPos()->z + offset));
		m_renderTarget->GetTransform()->SetForward(glm::vec3(0.0f, 0.0f, 1.0f));
		m_renderTarget->GetTransform()->SetChange(glm::vec3(0.0f, 0.0f, 1.0f + offset));
		m_renderTarget->GetTransform()->SetUp(glm::vec3(0.0f, 1.0f, 0.0f));
	}

	Player()
	{
	}

	inline void MoveForward(float amt)
	{
		m_camera->MoveForward(amt);
		m_renderTarget->GetTransform()->MoveForward(amt);
	}

	inline void MoveRight(float amt)
	{
		m_camera->MoveRight(amt);
		m_renderTarget->GetTransform()->MoveRight(amt);
	}

	inline void RotateY(float amt)
	{
		m_camera->RotateY(amt);
		m_renderTarget->GetTransform()->RotateY(amt);
		m_renderTarget->GetTransform()->GetPos()->x += amt * m_offset;
	}

	inline void Pitch(float amt)
	{
		m_camera->Pitch(amt);
	}

	inline float* GetY() { return &m_renderTarget->GetTransform()->GetPos()->y; }
	inline bool GetFlying() { return m_renderTarget->GetTransform()->GetFlying(); }

	inline void SetFlying(bool state)
	{
		m_camera->SetFlying(state);
		m_renderTarget->GetTransform()->SetFlying(state);
	}

	inline void SetY(float value)
	{
		m_camera->GetPos()->y = value;
		m_renderTarget->GetTransform()->GetPos()->y = value;
	}

	inline glm::vec3* GetCameraPosition() { return m_camera->GetPos(); }
	inline Transform* GetTargetTransform() { return m_renderTarget->GetTransform(); }
private:
	Camera* m_camera;
	RenderTarget* m_renderTarget;

	float m_offset;
};

#endif // !PLAYER_H

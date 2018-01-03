#include "renderCore.h"

RenderCore::RenderCore(const std::string& shaderPath, Camera& camera) :
	m_shader(shaderPath),
	m_camera(&camera)
{
}

void RenderCore::RenderTargets()
{
	m_shader.Bind();

	for (int i = 0; i < m_renderTargets.size(); i++)
	{
		m_renderTargets[i]->BindTexture();
		m_shader.Update(*m_renderTargets[i]->GetTransform(), *m_camera);
		m_renderTargets[i]->DrawMesh();
	}
}

void RenderCore::AddTarget(RenderTarget& target)
{
	m_renderTargets.push_back(&target);
}
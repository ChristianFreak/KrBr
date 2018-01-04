#ifndef RENDERCORE_H
#define RENDERCORE_H

#include "display.h"
#include "shader.h"
#include "camera.h"
#include "renderTarget.h"
#include <vector>
#include <string>

class RenderCore
{
public:
	RenderCore(const std::string& shaderPath, Camera& camera);
	
	void RenderTargets();
	void AddTarget(RenderTarget& target);
	inline std::vector<RenderTarget*> GetRenderTargets() { return m_renderTargets; }
private:
	std::vector<RenderTarget*> m_renderTargets;
	Shader m_shader;
	Camera* m_camera;
};

#endif // !


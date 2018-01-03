#ifndef RENDERTARGET_H
#define RENDERTARGET_H

#include "mesh.h"
#include "texture.h"
#include "transform.h"
#include <string>

struct RenderTarget
{
public:
	RenderTarget(const std::string& filePath, Vertex* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices);
	RenderTarget(const std::string& filePath, const std::string& objPath);

	RenderTarget(const RenderTarget& target) :
		m_texture(std::move(target.m_texture)),
		m_mesh(std::move(target.m_mesh))
	{
	}

	inline Transform* GetTransform() { return &m_transform; }

	void BindTexture();
	void DrawMesh();
private:
	Texture m_texture;
	Transform m_transform;
	Mesh m_mesh;
};

#endif // !RENDERTARGET_H


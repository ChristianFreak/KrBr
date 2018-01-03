#include "renderTarget.h"

RenderTarget::RenderTarget(const std::string& filePath, Vertex* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices) :
	m_texture(filePath),
	m_mesh(vertices, sizeof(vertices) / sizeof(vertices[0]), indices, sizeof(indices) / sizeof(indices[0]))
{
}

RenderTarget::RenderTarget(const std::string& filePath, const std::string& objPath) :
	m_texture(filePath),
	m_mesh(objPath)
{
}

void RenderTarget::BindTexture()
{
	m_texture.Bind();
}

void RenderTarget::DrawMesh()
{
	m_mesh.Draw();
}

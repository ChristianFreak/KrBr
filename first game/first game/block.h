#ifndef BLOCK_INCLUDED_H
#define BLOCK_INCLUDED_H

#include "texture.h";
#include "mesh.h";
#include "transform.h";
#include "shader.h";

class Block : private Texture, private Mesh
{
public:
	Block(const std::string& texturePath, int id);
	void DrawBlock(Shader& shader, const Camera& camera);

	inline Transform* GetTransform() { return &m_transform; }
protected:
private:
	Transform m_transform;

	int m_id;
};

#endif 


#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <GL/glew.h>

class Texture
{
public:
	Texture(const std::string& fileName);	
	Texture(const Texture& texture) = default;

	void Bind();

	virtual ~Texture();
protected:
private:
	GLuint m_texture;
};

#endif

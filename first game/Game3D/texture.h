#ifndef TEXTURE_H
#define TEXTURE_H

#include "GL/glew.h"
#include "stb_image.h"
#include <string>
#include <cassert>
#include <iostream>

using namespace std;

class Texture
{

public:
	Texture(const string& imageFilePath);
	virtual ~Texture();

	void Bind(unsigned int unit);

protected:

private:
	GLuint m_texture;
};

#endif // !TEXTURE_H
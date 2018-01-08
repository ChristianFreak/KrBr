#ifndef TEXTURE_H
#define TEXTURE_H

#include "GL\glew.h"
#include "stb_image.h"
#include <string>
#include <iostream>

using namespace std;

class Texture
{

public:
	Texture(const string& fileName);	
	virtual ~Texture();

	void Bind();

protected:

private:
	GLuint m_texture;

};

#endif

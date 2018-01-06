#ifndef SHADER_H
#define SHADER_H

#include "GL/glew.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Shader
{

public:
	Shader(const string& shaderFilePath);
	virtual ~Shader();

	void Bind();

protected:

private:
	string LoadShader(const string& shaderFilePath);
	GLuint CreateShader(const string& text, GLenum shaderType);
	void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const string& errorMessage);

	static const unsigned int NUM_SHADERS = 2;

	GLuint m_program;
	GLuint m_shaders[NUM_SHADERS];

};

#endif // !SHADER_H

#ifndef SHADER_H
#define SHADER_H

#include "GL/glew.h"
#include "transform.h"
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
	void Update(const Transform& transform);

protected:

private:
	string LoadShader(const string& shaderFilePath);
	GLuint CreateShader(const string& text, GLenum shaderType);
	void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const string& errorMessage);

	static const unsigned int NUM_SHADERS = 2;

	enum
	{
		TRANSFORM_U,

		NUM_UNIFORMS
	};

	GLuint m_program;
	GLuint m_shaders[NUM_SHADERS];
	GLuint m_uniforms[NUM_UNIFORMS];

};

#endif // !SHADER_H

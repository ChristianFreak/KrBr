#ifndef SHADER_H
#define SHADER_H

#include "GL\glew.h"
#include "transform.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
using namespace glm;

class Shader
{

public:
	Shader(const std::string& fileName);
	virtual ~Shader();

	void Bind();
	void Update(const Transform& transform, const Camera& camera);

protected:

private:

	string LoadShader(const std::string& fileName);
	void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
	GLuint CreateShader(const std::string& text, unsigned int type);

	static const unsigned int NUM_SHADERS = 2;
	static const unsigned int NUM_UNIFORMS = 3;

	GLuint m_program;
	GLuint m_shaders[NUM_SHADERS];
	GLuint m_uniforms[NUM_UNIFORMS];

};

#endif //!SHADER_H

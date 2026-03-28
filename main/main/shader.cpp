#include "shader.h"
#include <glew.h>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include "renderer.h"

#include <glm/glm.hpp>                   
#include <glm/gtc/matrix_transform.hpp>  
#include <glm/gtc/type_ptr.hpp>    
shaderprogramsource Shader::parseshader(const std::string& filepath) {
	enum class ShaderType {
		NONE = -1, VERTEX = 0, FREGMENT = 1
	};

	std::ifstream stream(filepath);
	std::string line;
	std::stringstream ss[2];
	ShaderType type = ShaderType::NONE;

	while (std::getline(stream, line)) {

		if (line.find("#shader") != std::string::npos) {

			if (line.find("vertex") != std::string::npos) {
				type = ShaderType::VERTEX;
			}


			else if (line.find("fragment") != std::string::npos) {
				type = ShaderType::FREGMENT;
			}


		}
		else if (type != ShaderType::NONE) {
			ss[(int)type] << line << '\n';
		}
	}
	std::cout << ss[0].str() << std::endl;
	return { ss[0].str(), ss[1].str() };
}


Shader::Shader(const std::string& filepath)
	:m_filepath(filepath), m_RendererID(0)
{
	shaderprogramsource source = parseshader(filepath);
	m_RendererID = CreateShader(source.vertexsource, source.fregmentsource);
}

Shader::~Shader()
{
	glDeleteProgram(m_RendererID);
}



unsigned int Shader::CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{
	unsigned int SProgram = glCreateProgram();
	unsigned int vShader = CompileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fShader = CompileShader(GL_FRAGMENT_SHADER,fragmentShader);

	glAttachShader(SProgram, vShader);
	glAttachShader(SProgram, fShader);
	glLinkProgram(SProgram);
	glValidateProgram(SProgram);

	glDeleteShader(vShader);
	glDeleteShader(fShader);

	return SProgram;
}





unsigned int Shader::CompileShader(unsigned int type, const std::string& source)
{
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (!result) {
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		auto* message = (char*) alloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);
		std::cout << "Faild to Compile" << (type == GL_VERTEX_SHADER ? "vertex" : "fragment");
		return 0;
	}
	return id;

}



void Shader::Bind() const
{
	glUseProgram(m_RendererID);
}

void Shader::Unbind() const
{
	glUseProgram(0);
}

void Shader::setuniform4f(const std::string& name, float v0, float v1, float v2, float v3)
{
	glUniform4f(GetUniformLocation(name), v0, v1, v2, v3);
}

void Shader::setuniformm4f(const std::string& name, const glm::mat4& matrix)
{
	glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, glm::value_ptr(matrix));
}


unsigned int Shader::GetUniformLocation(const std::string& name)
{
	
	if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
		return m_UniformLocationCache[name];

	int location = glGetUniformLocation(m_RendererID, name.c_str());

	if (location == -1)
		std::cout << "Warning: uniform '" << name << "' doesn't exist!" << std::endl;

	m_UniformLocationCache[name] = location;
	return location;
}

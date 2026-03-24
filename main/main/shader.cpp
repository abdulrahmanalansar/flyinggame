#include "shader.h"
#include <glew.h>
#include <string>
#include <sstream>
#include <fstream>
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

	return { ss[0].str(), ss[1].str() };
}


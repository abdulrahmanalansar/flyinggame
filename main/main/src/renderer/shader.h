#pragma once
#include<iostream>
#include <unordered_map>
#include <string>

#include <glm/glm.hpp>                   
#include <glm/gtc/matrix_transform.hpp>  
#include <glm/gtc/type_ptr.hpp>  

struct shaderprogramsource
{
	std::string vertexsource;
	std::string fregmentsource;
};

class Shader
{
private:
	unsigned int m_RendererID;
	std::string m_filepath;
	std::unordered_map<std::string, int> m_UniformLocationCache;
public:
	Shader(const std::string& filepath);
	~Shader();

	void Bind() const;
	void Unbind() const;
	void setuniform4f(const std::string& name, float v0, float v1, float v2, float v3);
	void setuniformm4f(const std::string& name, const glm::mat4& matrix);
	void setUniform1i(const std::string& name, int value);
	void setUniformvec3(const std::string& name, const glm::vec3& vector);

private:
	unsigned int GetUniformLocation(const std::string& name);
	unsigned int CompileShader(unsigned int type, const std::string& source);
	unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	shaderprogramsource parseshader(const std::string& filepath);
};
#pragma once
#include<iostream>

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
public:
	Shader(const std::string& filepath);
	~Shader();

	void Bind() const;
	void Unbind() const;
private:
	
	unsigned int CompileShader(unsigned int type, const std::string& source);
	unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	shaderprogramsource parseshader(const std::string& filepath);
};
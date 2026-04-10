#pragma once
#include<glew.h>
#include<glfw3.h>
#include"VertexArrayB.h"
#include"shader.h"
#include"IndexBufferO.h"
#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
x;\
ASSERT (GLLogCall(#x,__FILE__,__LINE__))			


void GLClearError();

bool GLLogCall(const char* function, const char* file, int line);

class Renderer {
private:
	double lastMouseX = 320.0, lastMouseY = 240.0;
	float rotateX = 0.0f, rotateY = 0.0f;
	GLFWwindow* window = nullptr;

	glm::vec3 cameye = glm::vec3(-5.0f, -5.0f, 14.0f);
	glm::vec3 campos = glm::vec3(0.0f, 0.0f, 13.0f);

public:

	int Windowinit();
	void clear();
	void mvp(Shader& s);
	void draw(const VertexArrayB& va, const IndexBufferO& ib, const Shader& shader);
	inline GLFWwindow* getWindow() const { return window; }

};


#pragma once
#include<glew.h>
#include<glfw3.h>
#include"VertexArrayB.h"
#include"shader.h"
#include"IndexBufferO.h"
#include "Gui.h"
#include <glm/gtc/type_ptr.hpp>

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

	glm::vec3 cameye = glm::vec3(-20.0f, -20.0f, 14.0f);
	glm::vec3 campos = glm::vec3(0.0f, 0.0f, 10.0f);
	glm::vec3 trans = glm::vec3(1.0f);
	useimgui app;
	
public:
	int Windowinit();
	void clear();
	void mvp(Shader& s);
	void draw(const VertexArrayB& va, const IndexBufferO& ib, const Shader& shader);
	inline GLFWwindow* getWindow() const { return window; }

	inline void newframe() { app.newframe(); }
	inline void guirender() { app.render(); }
	inline void guishutdown() { app.shutdown(); }	
	std::string cameyeName = "Camera Eye";
	std::string camposName = "Camera Position";



};


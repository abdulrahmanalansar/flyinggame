#pragma once
#include<glew.h>
#include"VertexArrayB.h"
#include"IndexBufferO.h"
#include"shader.h"

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
x;\
ASSERT (GLLogCall(#x,__FILE__,__LINE__))			


void GLClearError();

bool GLLogCall(const char* function, const char* file, int line);

class Renderer {
public:
	void clear();
//	void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
};


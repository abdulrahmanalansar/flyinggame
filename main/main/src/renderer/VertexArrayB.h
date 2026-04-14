#pragma once
#include"VertexBufferO.h"


class VertexBufferLayout;

class VertexArrayB {

private:
	unsigned int m_RendererID;
public:

	VertexArrayB();
	~VertexArrayB();
	
	void AddBuffer(const VertexBufferO& vb, const VertexBufferLayout& layout)const;
	void Bind()const;
	void Unbind()const;
};
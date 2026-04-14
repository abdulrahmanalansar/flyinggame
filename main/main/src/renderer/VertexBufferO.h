#pragma once
#include <glew.h>
class VertexBufferO
{
	private:
		
		unsigned int m_RendererID;
	public:
	VertexBufferO(unsigned int size, const void* data);
	~VertexBufferO();
	
	void Bind() const;
	void Unbind() const;
};


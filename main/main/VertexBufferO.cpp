#include "VertexBufferO.h"
#include <glew.h>

VertexBufferO::VertexBufferO(unsigned int size, const void* data)
{
	glGenBuffers(1, &m_RendererID);
	glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
	glBufferData(GL_ARRAY_BUFFER, size,data,GL_STATIC_DRAW);
}

VertexBufferO::~VertexBufferO()
{
}

void VertexBufferO::Bind() const
{
}

void VertexBufferO::Unbind() const
{
}

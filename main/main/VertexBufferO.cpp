#include <glew.h>
#include "VertexBufferO.h"

VertexBufferO::VertexBufferO(unsigned int size, const void* data)
{
	glGenBuffers(1, &m_RendererID);
	glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
	glBufferData(GL_ARRAY_BUFFER, size,data,GL_STATIC_DRAW);
}

VertexBufferO::~VertexBufferO()
{
	glDeleteBuffers(1, &m_RendererID);
}

void VertexBufferO::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
}

void VertexBufferO::Unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

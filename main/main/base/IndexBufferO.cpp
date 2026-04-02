#include <glew.h>
#include "IndexBufferO.h"


IndexBufferO::IndexBufferO(unsigned int count, const unsigned int* data)
{
	m_Count = count;
	glGenBuffers(1, &m_RendererID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);

}

IndexBufferO::~IndexBufferO()
{
	glDeleteBuffers(1, &m_RendererID);
}

void IndexBufferO::Bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
}


void IndexBufferO::Unbind() const
{	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

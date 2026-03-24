#include <glew.h>
#include "VertexArrayB.h"
#include "shader.h"
#include "VertexBufferO.h"
#include "IndexBufferO.h"

VertexArrayB::VertexArrayB()
{
	glGenVertexArrays(1, &m_RendererID);
}

VertexArrayB::~VertexArrayB()
{
	glDeleteVertexArrays(1, &m_RendererID);
}

void VertexArrayB::AddBuffer(const VertexBufferO& vb, const int& attribcount)
{
	Bind();
	vb.Bind();

	for (unsigned int i = 0; i < attribcount; i++) {

		glEnableVertexAttribArray(i);
		
		switch (i)
		{
		case 0:
			glVertexAttribPointer(i, 1, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (const void*)0);
			
			break;
			
		case 1:

			glVertexAttribPointer(i, 2, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)(3 * sizeof(float)));

			break;
			
		}

	}
}


void VertexArrayB::Bind() const
{
	glBindVertexArray(m_RendererID);
}

void VertexArrayB::Unbind() const
{
	glBindVertexArray( 0);
}
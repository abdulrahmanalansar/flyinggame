#include"VertexArrayB.h"
#include"VertexBufferLayout.h"

VertexArrayB::VertexArrayB()
{
	glGenVertexArrays(1, &m_RendererID);
}

VertexArrayB::~VertexArrayB()
{
	glDeleteVertexArrays(1, &m_RendererID);
}

void VertexArrayB::AddBuffer(const VertexBufferO& vb, const VertexBufferLayout& layout)const
{
	Bind();
	vb.Bind();
	const auto& elements = layout.GetElement();
	unsigned int offset = 0;
	for (unsigned int i = 0; i < elements.size(); i++) {
		const auto& element = elements[i];
		glEnableVertexAttribArray(i);
		glVertexAttribPointer(i,element.count,element.type,element.normalized,layout.GetStride(),
			reinterpret_cast<const void*>(static_cast<uintptr_t>(offset))
		);
		offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
	}
}

void VertexArrayB::Bind() const
{
	 glBindVertexArray(m_RendererID);

}

void VertexArrayB::Unbind() const
{
	glBindVertexArray(0);

}

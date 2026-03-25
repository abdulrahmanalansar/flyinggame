#pragma once
#include <glew.h>


class IndexBufferO
{
	private:
		unsigned int m_RendererID;
	public:
		IndexBufferO(unsigned int count, const unsigned int* data);
		~IndexBufferO();
		
		void Bind() const;
		void Unbind() const;
};


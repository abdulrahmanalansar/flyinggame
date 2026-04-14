#pragma once
#include <glew.h>

class IndexBufferO
{
	private:
		unsigned int m_RendererID;
		unsigned int m_Count;
	public:
		IndexBufferO(unsigned int count, const unsigned int* data);
		~IndexBufferO();
		
		void Bind() const;
		void Unbind() const;
		inline unsigned int GetCount() const { return m_Count; }
};


#pragma once
class VertexArrayB
{
private:
	unsigned int m_RendererID;
public:
	VertexArrayB();
	~VertexArrayB();

	void Bind() const;
	void Unbind() const;
};


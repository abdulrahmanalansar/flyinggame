#pragma once
class GenerateGrid
{
private:
	static const int Grid_size = 5;

	// 100 vertices * 3 floats
	static const int Vertex_count = Grid_size * Grid_size;
	static const int Vertex_float_count = Vertex_count * 3;

	static const int Index_count = (Grid_size - 1) * (Grid_size - 1) * 6;
public:
	static const unsigned int index_count = Index_count;
	float vertices[Vertex_float_count];
	unsigned int indices[Index_count];
	GenerateGrid();
	void generatevertices();
	void generateindices();

};


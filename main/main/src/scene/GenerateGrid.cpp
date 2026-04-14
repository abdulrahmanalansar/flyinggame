#include "GenerateGrid.h"
#include "texture.h"
#include <glm/glm.hpp>
#include <glm/gtc/noise.hpp>
#include <cstdlib> 

GenerateGrid::GenerateGrid()
{
    generatevertices();
    generateindices();
}

void GenerateGrid::generatevertices()
{
    int i = 0;
    for (int row = 0; row < Grid_size; row++)
    {
        for (int col = 0; col < Grid_size; col++)
        {

            float pos = 10 * glm::simplex(glm::vec3(col / 16.f, row / 16.f, 0.5f)) * glm::perlin(glm::vec3(col / 16.f, row / 16.f, 0.5f));
            vertices[i++] = col ;
            vertices[i++] = row ;
            vertices[i++] = pos; // use Perlin noise for height
            vertices[i++] = ((float)col / (Grid_size -1)) ;     // u
            vertices[i++] = (float)row / (Grid_size -1) ;     // v
			vertices[i++] = 0.0f;// vertex normal x
			vertices[i++] = 0.0f;// vertex normal y
			vertices[i++] = 1.0f;// vertex normal z
        }
    }
}

/*
->we have (Grid_size - 1) quads in each row and column, and each quad is made of 2 triangles
    , so we need 6 indices per quad
-> the indices for each quad are calculated based on the vertex indices of the top-left,
top-right, bottom-left, and bottom-right vertices

*/

void GenerateGrid::generateindices()
{
    int z = 0;
	for (int row = 0; row < Grid_size - 1; row++) {              // we have (Grid_size - 1) quads in each row
		for (int col = 0; col < Grid_size - 1; col++) {          // we have (Grid_size - 1) quads in each column
			unsigned int tl = row * Grid_size + col;             // top-left vertex index
            unsigned int tr = row * Grid_size + (col + 1);       // top-right vertex index
            unsigned int bl = (row + 1) * Grid_size + col;       // bottom-left vertex index
            unsigned int br = (row + 1) * Grid_size + (col + 1); // bottom-right vertex index

            indices[z++] = tl;
            indices[z++] = bl;
            indices[z++] = br;

            indices[z++] = br;
            indices[z++] = tr;
            indices[z++] = tl;
        }
    }

}




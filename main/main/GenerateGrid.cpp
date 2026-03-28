#include "GenerateGrid.h"

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
            vertices[i++] = col * 0.1f;
            
            vertices[i++] = row * 0.1f;
        }

    }

}

void GenerateGrid::generateindices()
{
    int z = 0;
    for (int row = 0; row < Grid_size - 1; row++) {
        for (int col = 0; col < Grid_size - 1; col++) {
            unsigned int tl = row * Grid_size + col;
            unsigned int tr = row * Grid_size + (col + 1);
            unsigned int bl = (row + 1) * Grid_size + col;
            unsigned int br = (row + 1) * Grid_size + (col + 1);

            indices[z++] = tl;
            indices[z++] = tr;
            indices[z++] = br;

            indices[z++] = tl;
            indices[z++] = br;
            indices[z++] = bl;
        }
    }

}




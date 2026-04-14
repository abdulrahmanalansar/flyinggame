#pragma once
#include <string>
#include <vector>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

struct Vertex {
    float x, y, z;
    float nx, ny, nz; // Normals
    float u, v;       // UVs
};

class ModelImporter {
public:
    bool DoImport(const std::string& pFile);

    // Extracted data storage
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
};

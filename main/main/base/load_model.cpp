/*bool ModelImporter::DoImport(const std::string& pFile)
#include "load_model.h"
#include <iostream>

{
    Assimp::Importer importer;

    // 1. Read the file
    const aiScene* scene = importer.ReadFile(pFile,
        aiProcess_Triangulate |
        aiProcess_FlipUVs |
        aiProcess_JoinIdenticalVertices);

    // 2. Check for errors
    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        std::cout << "Assimp Error: " << importer.GetErrorString() << std::endl;
        return false;
    }

    // 3. Process the first mesh (for simplicity)
    // Real models often have multiple meshes; you can loop through scene->mNumMeshes
    aiMesh* mesh = scene->mMeshes[0];

    // Clear old data
    vertices.clear();
    indices.clear();

    // 4. Extract Vertex Data
    for (unsigned int i = 0; i < mesh->mNumVertices; i++) {
        Vertex vertex;

        // Positions
        vertex.x = mesh->mVertices[i].x;
        vertex.y = mesh->mVertices[i].y;
        vertex.z = mesh->mVertices[i].z;

        // Normals (if available)
        if (mesh->HasNormals()) {
            vertex.nx = mesh->mNormals[i].x;
            vertex.ny = mesh->mNormals[i].y;
            vertex.nz = mesh->mNormals[i].z;
        }

        // Texture Coordinates (UVs)
        if (mesh->mTextureCoords[0]) {
            vertex.u = mesh->mTextureCoords[0][i].x;
            vertex.v = mesh->mTextureCoords[0][i].y;
        }
        else {
            vertex.u = 0.0f;
            vertex.v = 0.0f;
        }

        vertices.push_back(vertex);
    }

    // 5. Extract Index Data (Faces)
    for (unsigned int i = 0; i < mesh->mNumFaces; i++) {
        aiFace face = mesh->mFaces[i];
        for (unsigned int j = 0; j < face.mNumIndices; j++) {
            indices.push_back(face.mIndices[j]);
        }
    }

    std::cout << "Successfully loaded: " << pFile << std::endl;
    std::cout << "Vertices: " << vertices.size() << " | Indices: " << indices.size() << std::endl;
   
    return true;
}
*/
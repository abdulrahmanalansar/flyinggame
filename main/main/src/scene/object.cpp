#include "object.h"


void object::creategrid()
{
    if (vb) return; // already initialized

    vb = std::make_unique<VertexBufferO>(sizeof(grid.vertices), grid.vertices);
    layout.push<float>(3); // position
    layout.push<float>(2); // uv
    layout.push<float>(3); // normal
    va.AddBuffer(*vb, layout);
    ib = std::make_unique<IndexBufferO>(grid.index_count, grid.indices);
}

void object::loadmodel(const std::string& filepath)
{
    if (vb) return; // already initialized

    ModelImporter importer;
    importer.DoImport(filepath);

    vb = std::make_unique<VertexBufferO>(
        importer.vertices.size() * sizeof(Vertex),
        importer.vertices.data()
    );
    layout.push<float>(3); // position
    layout.push<float>(2); // uv
    layout.push<float>(3); // normal
    va.AddBuffer(*vb, layout);
    ib = std::make_unique<IndexBufferO>(
        importer.indices.size(),
        importer.indices.data()
    );
}



void object::modeltrans(glm::vec3 translation, glm::vec3 rotation, Shader& shader)
{
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, translation);
    model = glm::rotate(model, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
    shader.setuniformm4f("model", model);
}

void object::setObjectColor(glm::vec3 color, Shader& shader)
{
	shader.setUniformvec3("objectColor", color);
}


void object::draw(Shader& shader, Renderer& renderer)const
{
	shader.Bind();
	
	renderer.draw(va, *ib, shader);
}



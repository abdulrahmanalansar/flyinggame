#pragma once
#include <glew.h>
#include "VertexArrayB.h"
#include "VertexBufferO.h"
#include "IndexBufferO.h"
#include "shader.h"
#include "VertexBufferLayout.h"
#include "GenerateGrid.h"
#include "texture.h"
#include "load_model.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <memory>
class object
{
	public:
		void creategrid();
		void loadmodel(const std::string& filepath);
		void modeltrans(glm::vec3 translation, glm::vec3 rotation, Shader& shader);
		void setObjectColor(glm::vec3 color, Shader& shader);

private:

	GenerateGrid grid;
	VertexArrayB va;
	VertexBufferLayout layout;


	std::unique_ptr<VertexBufferO> vb;
	std::unique_ptr<IndexBufferO> ib;
public:
	void draw(Shader& shader, Renderer& renderer)const;
};


#include"renderer.h"
#include<iostream>
#include"shader.h"
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>

void GLClearError() 
{
    while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char* function, const char* file, int line)
{
    while (GLenum error = glGetError()) {
        std::cout << "[openGL Error](" << error << ")" << function << " " << file << " " << line << std::endl;
    }
    return true;
}

void Renderer::clear(){
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::mvp(Shader& s)
{
    
    glm::mat4 model = glm::mat4(1.0f);
	model = glm::rotate(model, glm::radians(-45.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    glm::mat4 view = glm::mat4(1.0f);
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f)); 

    glm::mat4 projection = glm::perspective(
        glm::radians(30.0f),   
        640.0f / 480.0f,
        0.1f, 100.0f
    );

    s.setuniformm4f("model", model);
    s.setuniformm4f("view", view);
    s.setuniformm4f("projection", projection);

}









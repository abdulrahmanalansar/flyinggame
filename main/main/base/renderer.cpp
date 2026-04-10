#include"renderer.h"
#include<glfw3.h>
#include<iostream>
#include"shader.h"



#define GLM_ENABLE_EXPERIMENTAL
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtx/string_cast.hpp>
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

int Renderer::Windowinit()
{
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(monitor);
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(mode->width/2, mode->height/2, "Hello World", NULL, NULL);
    if (!window){glfwTerminate();return -1;}


    glfwMakeContextCurrent(window);


    glewExperimental = GL_TRUE;    
    if (glewInit() != GLEW_OK) {
        std::cout << "GLEW init failed\n";
        return -1;
    }
    glEnable(GL_DEPTH_TEST);
	return 0;

}

void Renderer::clear(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::mvp(Shader& s)
{
	
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::rotate(model, glm::radians(rotateX), glm::vec3(0.0f, 0.0f, 1.0f)); 

    glm::mat4 view = glm::lookAt(cameye * glm::vec3(1.0f, 1.0f, 1.0f), campos, glm::vec3(0.0f, 0.0f, 1.0f));
	
    glm::mat4 projection = glm::perspective(glm::radians(30.0f), 640.0f / 480.0f, 0.1f, 100.0f);

   
    s.Bind();
    s.setuniformm4f("projection", projection);
    s.setuniformm4f("model", model  );
    s.setuniformm4f("view", view);
}

void Renderer::draw(const VertexArrayB& va, const IndexBufferO& ib, const Shader& shader)
{
	
    
    GLCall( shader.Bind());
    va.Bind();
    ib.Bind();
	glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            
}









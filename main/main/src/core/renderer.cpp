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


   window = glfwCreateWindow(mode->width / 2, mode->height / 2, "Hello World", NULL, NULL);
    if (!window) { glfwTerminate(); return -1; }

   glfwMakeContextCurrent(window);


    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cout << "GLEW init failed\n";
        return -1;
    }

    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;

  
   app.init(window);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
  



    return 0;
}

void Renderer::clear(){
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::mvp(Shader& s)
{
    glm::mat4 view = glm::lookAt(cameye ,campos , glm::vec3(0.0f, 0.0f, 1.0f));
	
    glm::mat4 projection = glm::perspective(glm::radians(30.0f), 640.0f / 480.0f, 0.1f, 100.0f);

   
    s.Bind();
    s.setuniformm4f("projection", projection);
    //s.setuniformm4f("model", model);
    s.setuniformm4f("view", view);

	useimgui::createslider(cameye, cameyeName);
	useimgui::createslider(campos, camposName);

	// Set lighting uniforms
	s.setUniformvec3("viewPos", cameye);
	s.setUniformvec3("lightPos",glm::vec3(10.0f, 10.0f, 10.0f));
	s.setUniformvec3("lightColor", glm::vec3(1.0f, 1.0f, 1.0f));
}

void Renderer::draw(const VertexArrayB& va, const IndexBufferO& ib, const Shader& shader)
{

	

    glCullFace(GL_FRONT);
	//glPolygonMode(GL_FRONT_AND_BACK , GL_LINE);
    shader.Bind();
    va.Bind();
    ib.Bind();
	glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr);
   
}









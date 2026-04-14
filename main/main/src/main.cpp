#include <glew.h>
#include <glfw3.h>
#include <iostream>
#include "renderer.h"
#include "shader.h"
#include "texture.h"
#include "object.h"

int main()
{
 
	Renderer renderer;
	renderer.Windowinit();
   

    Shader shader("main/shader/shader.shader");
	object obj,model;
	obj.creategrid();
	model.loadmodel("assets/jet/jet.obj");
	
    glm::vec3 modeltrans(0.0f, 0.0f, 0.0f);
	glm::vec3 modelrot(0.0f, 0.0f, 0.0f);
	std::string modelname = "Model Position";  
	std::string modelrotname = "Model Rotation";
    while (!glfwWindowShouldClose(renderer.getWindow()))
    {
		renderer.newframe();
        renderer.clear();
        renderer.mvp(shader); // sets view + projection uniforms


        useimgui::createslider(modeltrans, modelname);
		obj.modeltrans(glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f), shader);
		obj.draw(shader, renderer);


		useimgui::createslider(modelrot, modelrotname);
		model.modeltrans(modeltrans, modelrot, shader);
		model.draw(shader, renderer);
		renderer.guirender();
		glfwSwapBuffers(renderer.getWindow());
        glfwPollEvents();
    }

	renderer.guishutdown();
    glfwTerminate();
    return 0;
}
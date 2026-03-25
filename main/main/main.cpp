#include <glew.h>
#include <glfw3.h>
#include <iostream>
#include "renderer.h"
#include "VertexBufferO.h"
#include "VertexArrayB.h"
#include "IndexBufferO.h"
#include "shader.h"
#include "VertexBufferLayout.h"

int main()
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL); 
    if (!window)
    
    {
        glfwTerminate();
        return -1;
    }


    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        std::cout << "GLEW init failed\n";
    }

    float vertex[] = {
        -0.5f, -0.5f,
         0.5f, -0.5f,
         0.5f,  0.5f,
		 -0.5f, 0.5f
    };

    unsigned int index[] = {
        0, 1, 2,
        2, 3, 0
    };
    std::cout << sizeof(vertex) << std::endl;
	
	VertexArrayB va;
    VertexBufferO vb( sizeof(vertex),vertex);
	vb.Bind();
	VertexBufferLayout layout;
    layout.push<float>(2);
	va.Bind();
	va.AddBuffer(vb, layout);
    IndexBufferO ib(6, index);
	Shader shader("main/shader.shader");
	shader.Bind();
	ib.Bind();




    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
		va.Bind();
		shader.Bind();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
        glfwSwapBuffers(window);


        glfwPollEvents();
    }


   
    glfwTerminate();
    return 0;
}
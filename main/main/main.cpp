#include <glew.h>
#include <glfw3.h>
#include <iostream>
#include "renderer.h"
#include "VertexBufferO.h"
#include "VertexArrayB.h"
#include "IndexBufferO.h"
#include "shader.h"
#include "VertexBufferLayout.h"
#include "GenerateGrid.h"

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
    
    GenerateGrid grid;

    VertexArrayB va;
    va.Bind();

    VertexBufferO vb(sizeof(grid.vertices), grid.vertices);
    vb.Bind();

    VertexBufferLayout layout;
    layout.push<float>(2);

    va.AddBuffer(vb, layout);

    Shader shader("main/shader.shader");
    shader.Bind();

    IndexBufferO ib(GenerateGrid::index_count, grid.indices);
    ib.Bind();


    Renderer renderer;
    renderer.mvp(shader);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        va.Bind();
        shader.Bind();
        glDrawElements(GL_TRIANGLES, GenerateGrid::index_count, GL_UNSIGNED_INT, nullptr);
        glfwSwapBuffers(window);

		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glfwPollEvents();
    }



    glfwTerminate();
    return 0;
}
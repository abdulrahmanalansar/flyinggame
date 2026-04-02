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
#include "input.h"
#include "load_model.h"
int main()
{
    Renderer renderer;
	
	 renderer.Windowinit();
    
     ModelImporter import;
    import.DoImport("assets/jet/jet.obj");

    GenerateGrid grid;

    VertexArrayB va;
    va.Bind();

    VertexBufferO vb(import.vertices.size() * sizeof(Vertex), import.vertices.data());
    vb.Bind();

    VertexBufferLayout layout;
    layout.push<float>(3); // Position
    layout.push<float>(3); // Normals
    layout.push<float>(2); // UVs

    va.AddBuffer(vb, layout);

    Shader shader("main/base/shader.shader");
    shader.Bind();

    IndexBufferO ib(import.indices.size(), import.indices.data());
    ib.Bind();


    

    while (!glfwWindowShouldClose(renderer.getWindow()))
    {
      
		renderer.clear();
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);  
        shader.Bind();
        renderer.mvp(shader);
        renderer.draw(va, ib, shader);

        glfwSwapBuffers(renderer.getWindow());
        glfwPollEvents();
    }



    glfwTerminate();
    return 0;
}
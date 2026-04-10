#include <glew.h>
#include <glfw3.h>
#include <iostream>
#include "renderer.h"
#include "VertexArrayB.h"
#include "VertexBufferO.h"
#include "IndexBufferO.h"
#include "shader.h"
#include "VertexBufferLayout.h"
#include "GenerateGrid.h"
#include "texture.h"
#include "load_model.h"

int main()
{
	Renderer renderer;
	renderer.Windowinit();

	GenerateGrid grid;
    Shader shader("main/base/shader.shader");
    texture texture("main/texture/wall.jpg");  // ← here, before loop


    // Tell the shader which texture slot to use — do this once at startup
    texture.bind(0);
    shader.setUniform1i("u_Texture", 0);

    VertexArrayB va;
	VertexBufferO vb(sizeof(grid.vertices), grid.vertices);
    VertexBufferLayout layout;
	layout.push<float>(3); // vertex positions
	layout.push<float>(2); // uv coordinates
	layout.push<float>(3); // vertex normals
	va.AddBuffer(vb, layout);
	IndexBufferO ib(grid.index_count, grid.indices);

  
   

    while (!glfwWindowShouldClose(renderer.getWindow()))
    {
        renderer.clear();
        shader.Bind();
        renderer.mvp(shader); // sets view + projection uniforms

		renderer.draw(va, ib, shader);
        glfwSwapBuffers(renderer.getWindow());
        glfwPollEvents();
    }


    glfwTerminate();
    return 0;
}
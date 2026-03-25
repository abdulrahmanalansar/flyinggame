#include"renderer.h"
#include<iostream>
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

/*void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const
{
    shader.Bind();
    va.bind();
    glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr);
}*/

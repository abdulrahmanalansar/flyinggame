#include "input.h"
#include<iostream>
void input::init(GLFWwindow* window)
{
	glfwSetKeyCallback(window, keay_callback);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);
}

void input::keay_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

}

void input::mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	//std::cout << "Mouse moved: " << xpos << ", " << ypos << std::endl;
}

void input::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	//std::cout << "Mouse scrolled: " << xoffset << ", " << yoffset << std::endl;
}

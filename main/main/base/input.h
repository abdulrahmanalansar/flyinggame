#pragma once
#include<glfw3.h>
class input
{
	public:
		static void init(GLFWwindow* window);
private:
	static void keay_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void mouse_callback(GLFWwindow* window, double xpos, double ypos);
	static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
	
};


#pragma once
#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>
class useimgui
{
public:
	float panelWidth = 300.0f;
	void init(GLFWwindow* window);
	void newframe();
	static void createslider(glm::vec3& value, std::string &name);
    void render();
	void shutdown();
};


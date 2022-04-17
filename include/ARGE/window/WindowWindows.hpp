#pragma once

#include "ARGE/graphics/OpenGL.hpp"

namespace ARGE
{
	class Window
	{
	public:
		Window();
		~Window();

		void Create();

		bool Loop();

	private:
		GLFWwindow* window = nullptr;

		void WindowSizeCallback(GLFWwindow* window, int width, int height);
	};

	void framebuffer_size_callback(GLFWwindow* window, int width, int height);
}
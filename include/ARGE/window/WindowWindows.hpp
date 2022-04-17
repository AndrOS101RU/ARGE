#pragma once

#include "ARGE/graphics/OpenGL.hpp"

namespace ARGE
{
	class Window
	{
	public:
		Window();
		~Window();

		bool Loop();

	private:
		GLFWwindow* window = nullptr;

		void WindowSizeCallback(int x, int y, int width, int height);
	};
}
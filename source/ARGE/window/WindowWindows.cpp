#include "ARGE/window/WindowWindows.hpp"

namespace ARGE
{
	Window::Window() 
	{
		
	}

	Window::~Window()
	{
		glfwDestroyWindow(window);
	}

	void Window::Create() 
	{
		// glfw preferences
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		// Create a window
		window = glfwCreateWindow(640, 480, "ARGE", NULL, NULL);
		if (window == NULL)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			exit(-1);
		}
		glfwMakeContextCurrent(window);
		glfwSetFramebufferSizeCallback(window, WindowSizeCallback);

		// Initialize GLAD
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
			exit(-1);
		}

		glViewport(0, 0, 640, 480);
	}

	bool Window::Loop()
	{
		if (!glfwWindowShouldClose)
		{
			glfwSwapBuffers(window);
			glfwPollEvents();
			return true;
		}
		else
			return false;
	}

	void Window::WindowSizeCallback(int x, int y, int width, int height) {
		glViewport(x, y, width, height);
	}
}
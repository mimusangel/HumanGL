#include <iostream>
using namespace std;

#include "window.hpp"
#include "shaders.hpp"

int main()
{
	if (!glfwInit())
		cout << "Erreur init glfw!" << endl;
	else
	{
		Window win(1280, 720, "HumanGL");
		if (win.getError().length() > 0)
			std::cout << win.getError() << endl;
		else
		{
			Shaders sample;
			if (!sample.loadVertexShader("sample.vert"))
				return (0);
			if (!sample.loadFragmentShader("sample.frag"))
				return (0);
			if (!sample.build())
				return (0);
			while (win.isOpen())
			{
				win.makeContextCurrent();

				win.update();
			}
		}
	}
	return (0);
}

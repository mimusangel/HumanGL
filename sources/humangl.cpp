#include <iostream>
using namespace std;

#include "window.hpp"

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
			while (win.isOpen())
			{
				win.makeContextCurrent();

				win.update();
			}
		}
	}
	return (0);
}

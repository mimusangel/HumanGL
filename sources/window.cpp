#include "window.hpp"

/*
** Static function Callback
*/
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	Window	*win;

	win = (Window *)glfwGetWindowUserPointer(window);
	if (!win)
		return ;
}

static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	Window	*win;

	win = (Window *)glfwGetWindowUserPointer(window);
	if (!win)
		return ;
}

static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	Window	*win;

	win = (Window *)glfwGetWindowUserPointer(window);
	if (!win)
		return ;
}

/*
** Class Window
*/

Window::Window(int width, int height, std::string title) : _grab(false)
{
	if ((_win = glfwCreateWindow(width, height, title.c_str(), NULL, NULL)))
	{
		glfwWindowHint(GLFW_SAMPLES, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwMakeContextCurrent(_win);
		glfwSetWindowUserPointer(_win, this);
		glfwSetKeyCallback(_win, key_callback);
		glfwSetCursorPosCallback(_win, cursor_position_callback);
		glfwSetMouseButtonCallback(_win, mouse_button_callback);
		glewExperimental = GL_TRUE;
		if (glewInit() != GLEW_OK)
			_error = "Erreur init glew!";
	}
	else
		_error = "La fenetre n'a pas pu etre creer.";

}

Window::~Window()
{
	if (_win)
		glfwDestroyWindow(_win);
	glfwTerminate();
}

std::string			&Window::getError(void)
{
	return (_error);
}

void				Window::makeContextCurrent(void)
{
	glfwMakeContextCurrent(_win);
}

void				Window::update(void)
{
	glfwSwapBuffers(_win);
	glfwPollEvents();
}

void				Window::setTitle(std::string title)
{
	glfwSetWindowTitle(_win, title.c_str());
}

bool				Window::isGrabbed(void)
{
	return (_grab);
}

void				Window::setGrab(bool grab)
{
	_grab = grab;
	if (_grab)
		glfwSetInputMode(_win, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	else
		glfwSetInputMode(_win, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}

bool				Window::isOpen(void)
{
	return (!glfwWindowShouldClose(_win));
}

#include "window.hpp"
#include "debug.hpp"
#define SMOOTH_DEPTH 3

/*
** Static function Callback
*/
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	Window	*win;

	win = (Window *)glfwGetWindowUserPointer(window);
	if (!win)
		return ;
	if (action == GLFW_PRESS)
	{
		if (key == GLFW_KEY_ESCAPE)
		{
			if (win->isGrabbed())
				win->setGrab(false);
			else
				win->close();
		}
		else if (key == GLFW_KEY_SPACE)
		{
			win->setGrab(true);
		}
	}
}

static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	Window	*win;

	win = (Window *)glfwGetWindowUserPointer(window);
	if (!win)
		return ;
	win->dirMouse[0] = xpos - win->mouse[0];
	win->dirMouse[1] = ypos - win->mouse[1];
	win->mouse[0] = xpos;
	win->mouse[1] = ypos;
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

Window::Window(int width, int height, std::string title) : _grab(false), mouse(0), dirMouse(0)
{
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	if ((_win = glfwCreateWindow(width, height, title.c_str(), NULL, NULL)))
	{
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

mmatrix::Vec2	mouse_smooth(const mmatrix::Vec2 &v)
{
	static int		c;
	static mmatrix::Vec2		buf[SMOOTH_DEPTH];
	mmatrix::Vec2			t;

	buf[c++] = v;
	if (c == SMOOTH_DEPTH)
		c = 0;
	for (int i = 0; i < SMOOTH_DEPTH; i++)
		t += buf[i];
	return (t /= SMOOTH_DEPTH);
}

void				Window::update(void)
{
	dirMouse = Vec2(0);
	dirMouseSmooth = Vec2(0);
	glfwSwapBuffers(_win);
	glfwPollEvents();
	dirMouseSmooth = mouse_smooth(dirMouse);
}

void				Window::setTitle(std::string title)
{
	glfwSetWindowTitle(_win, title.c_str());
}

void				Window::close(void)
{
	glfwSetWindowShouldClose(_win, GLFW_TRUE);
}

bool				Window::isGrabbed(void)
{
	return (_grab);
}

void				Window::setGrab(bool grab)
{
	_grab = grab;
	if (_grab)
	{
		glfwSetInputMode(_win, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		dirMouse[0] = 0;
		dirMouse[1] = 0;
	}
	else
		glfwSetInputMode(_win, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}

bool				Window::isOpen(void)
{
	return (!glfwWindowShouldClose(_win));
}

GLFWwindow			*Window::getGLFW(void)
{
	return (_win);
}

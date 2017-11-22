#include "camera.hpp"


Camera::Camera(Window &win, const Vec3 &pos, const Quat &rot) :
	Transform(pos, rot)
{
	_win = &win;
}
Camera		&Camera::move(void)
{
	GLFWwindow	*win = _win->getGLFW();

	Vec3	pos;
	if (glfwGetKey(win, GLFW_KEY_A) == GLFW_PRESS)
		pos -= Vec3(1, 0 ,0);
	if (glfwGetKey(win, GLFW_KEY_D) == GLFW_PRESS)
		pos += Vec3(1, 0, 0);
	if (glfwGetKey(win, GLFW_KEY_Q) == GLFW_PRESS)
		pos -= Vec3(0, 1, 0);
	if (glfwGetKey(win, GLFW_KEY_E) == GLFW_PRESS)
		pos += Vec3(0, 1, 0);
	if (glfwGetKey(win, GLFW_KEY_S) == GLFW_PRESS)
		pos -= Vec3(0, 0, 1);
	if (glfwGetKey(win, GLFW_KEY_W) == GLFW_PRESS)
		pos += Vec3(0, 0, 1);

	if (glfwGetKey(win, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
		pos *= 0.1f;
	else
		pos *= 0.01f;
	this->translate(pos);
	return (*this);
}
Camera		&Camera::setRotateEuler(const Vec3 &euler)
{
	_euler = euler;
	setRotate(_euler);
	return (*this);
}
Camera		&Camera::rotateEuler(const Vec3 &euler)
{
	if (Vec3(0) != euler)
	{
		_euler += euler;
		setRotate(_euler);
	}
	return (*this);
}
Camera		&Camera::translate(const Vec3 &value)
{
	_position += _rotate * ((Vec3)value).negate();
	return (*this);
}

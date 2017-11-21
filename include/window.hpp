#ifndef WINDOW_HPP
# define WINDOW_HPP

# include "humangl.hpp"

class Window {

private:
	GLFWwindow			*_win;
	std::string			_error;
	bool				_grab;

public:
	mmatrix::Vec2		mouse;
	mmatrix::Vec2		dirMouse;
	Window(int width, int height, std::string title);
	~Window();
	std::string			&getError(void);
	void				makeContextCurrent(void);
	void				update(void);
	void				setTitle(std::string title);
	bool				isGrabbed(void);
	void				setGrab(bool grab);
	bool				isOpen(void);
	GLFWwindow			*getGLFW(void);
};

#endif

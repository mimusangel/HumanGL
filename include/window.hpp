#ifndef WINDOW_HPP
# define WINDOW_HPP

# include "humangl.hpp"

class Window {

private:
	GLFWwindow			*_win;
	std::string			_error;
	bool				_grab;

public:
	int					width;
	int					height;
	mmatrix::Vec2		mouse;
	mmatrix::Vec2		dirMouse;
	mmatrix::Vec2		dirMouseSmooth;
	mmatrix::Mat4x4		matProjection;
	Window(int width, int height, std::string title);
	~Window();
	std::string			&getError(void);
	void				makeContextCurrent(void);
	void				update(void);
	void				setTitle(std::string title);
	void				close(void);
	bool				isGrabbed(void);
	void				setGrab(bool grab);
	bool				isOpen(void);
	GLFWwindow			*getGLFW(void);
};

#endif

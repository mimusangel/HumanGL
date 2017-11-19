#ifndef WINDOW_HPP
# define WINDOW_HPP

# define GLEW_STATIC
# include <GL/glew.h>
# include <GLFW/glfw3.h>
# include <string>

class Window {

private:
	GLFWwindow			*_win;
	std::string			_error;
	bool				_grab;

public:
	Window(int width, int height, std::string title);
	~Window();
	std::string			&getError(void);
	void				makeContextCurrent(void);
	void				update(void);
	void				setTitle(std::string title);
	bool				isGrabbed(void);
	void				setGrab(bool grab);
	bool				isOpen(void);
};

#endif

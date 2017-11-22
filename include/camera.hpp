#ifndef CAMERA_HPP
# define CAMERA_HPP

# include "window.hpp"
# include "transform.hpp"

using namespace mmatrix;

class	Camera : public Transform
{
public:
	Camera(Window &win, const Vec3 &pos = Vec3(), const Quat &rot = Quat(0, 0, 0, 1));
	Camera		&move(void);
	Camera		&setRotateEuler(const Vec3 &euler);
	Camera		&rotateEuler(const Vec3 &euler);
	Camera		&translate(const Vec3 &value);

private:
	Window	*_win;
	Vec3	_euler;
};

#endif

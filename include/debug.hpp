#ifndef DEBUG_HPP
# define DEBUG_HPP


# include "humangl.hpp"
using namespace mmatrix;

class Debug {
public:
	static void			print(Vec2 &value);
	static void			print(Vec3 &value);
	static void			print(Vec4 &value);
	static void			print(Mat4x4 &value);
	static void			print(Quat &value);
};

#endif

#ifndef DEBUG_HPP
# define DEBUG_HPP


# include "humangl.hpp"
using namespace mmatrix;

class Debug {
public:
	static void			print(const Vec2 &value);
	static void			print(const Vec3 &value);
	static void			print(const Vec4 &value);
	static void			print(const Mat4x4 &value);
	static void			print(const Quat &value);
};

#endif

#ifndef TRANSFORM_HPP
# define TRANSFORM_HPP

# include "humangl.hpp"
using namespace mmatrix;

class Transform
{
private:
	Transform	*_parent;
	Vec3		_position;
	Quat		_rotate;

public:
	Transform(const Vec3 &pos = Vec3(), const Quat &rot = Quat(0, 0, 0, 1));
	Transform	&setParent(Transform *parent);
	Transform	&rotate(const Vec3 &axis, float angle);
	Transform	&setRotate(const Vec3 &angle);
	Transform	&translate(const Vec3 &value);
	Mat4x4		toMatrix(void);
};

#endif

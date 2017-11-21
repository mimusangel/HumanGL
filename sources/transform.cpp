#include "transform.hpp"
using namespace mmatrix;

Transform::Transform(const Vec3 &pos, const Quat &rot) : _parent(nullptr), _position(pos), _rotate(rot)
{}

Transform	&Transform::setParent(Transform *parent)
{
	_parent = parent;
	return (*this);
}

Transform	&Transform::rotate(Vec3 &axis, float angle)
{
	_rotate = Quat::Rotate(axis, TORADIANS(angle)) * _rotate;
	return (*this);
}

Transform	&Transform::translate(Vec3 &value)
{
	_position += value;
	return (*this);
}

Mat4x4		Transform::toMatrix(void)
{
	Mat4x4	translateMat = Mat4x4::Identity();
	translateMat.set_translate(_position);
	Mat4x4	rotationMat(_rotate);
	Mat4x4	parentMat = Mat4x4::Identity();
	if (_parent != nullptr)
		parentMat = _parent->toMatrix();
	return (parentMat * (translateMat * rotationMat));
}

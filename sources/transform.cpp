#include <cmath>
#include <cstring>
#include "transform.hpp"
using namespace mmatrix;

Transform::Transform(const Vec3 &pos, const Quat &rot) : _parent(nullptr), _position(pos), _rotate(rot)
{}

Transform	&Transform::setParent(Transform *parent)
{
	_parent = parent;
	return (*this);
}

Transform	&Transform::rotate(const Vec3 &axis, float angle)
{
	_rotate = Quat::Rotate(axis, angle) * _rotate;
	float magnitude = sqrtf(_rotate[0] * _rotate[0] + _rotate[1] * _rotate[1] + _rotate[2] * _rotate[2] + _rotate[3] * _rotate[3]);
	_rotate[0] /= magnitude;
	_rotate[1] /= magnitude;
	_rotate[2] /= magnitude;
	_rotate[3] /= magnitude;
	return (*this);
}

Transform	&Transform::setRotate(const Vec3 &angle)
{
	_rotate = Quat::SetRotate(angle);
	return (*this);
}

Transform	&Transform::translate(const Vec3 &value)
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

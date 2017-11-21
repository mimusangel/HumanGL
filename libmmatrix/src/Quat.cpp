#include "mmatrix.hpp"
#include <cmath>
#include <cstring>

namespace mmatrix
{
	Quat::Quat(void)
	{
		memset(this->_val, 0, sizeof(float) * 4);
	}
	Quat::Quat(const Mat4x4 &v)
	{
		float	tr = v[0][0] + v[1][1] + v[2][2];
		float	s;

		if (tr > 0)
		{
			s = sqrtf(tr + 1.0) * 2;
			this->_val[3] = 0.25 * s;
			this->_val[0] = (v[2][1] - v[1][2]) / s;
			this->_val[1] = (v[0][2] - v[2][0]) / s;
			this->_val[2] = (v[1][0] - v[0][1]) / s;
		}
		else if ((v[0][0] > v[1][1])&(v[0][0] > v[2][2]))
		{
			s = sqrtf(1.0 + v[0][0] - v[1][1] - v[2][2]) * 2;
			this->_val[3] = (v[2][1] - v[1][2]) / s;
			this->_val[0] = 0.25 * s;
			this->_val[1] = (v[0][1] + v[1][0]) / s;
			this->_val[2] = (v[0][2] + v[2][0]) / s;
		}
		else if (v[1][1] > v[2][2])
		{
			s = sqrtf(1.0 + v[1][1] - v[0][0] - v[2][2]) * 2;
			this->_val[3] = (v[0][2] - v[2][0]) / s;
			this->_val[0] = (v[0][1] + v[1][0]) / s;
			this->_val[1] = 0.25 * s;
			this->_val[2] = (v[1][2] + v[2][1]) / s;
		}
		else
		{
			s = sqrtf(1.0 + v[2][2] - v[0][0] - v[1][1]) * 2;
			this->_val[3] = (v[1][0] - v[0][1]) / s;
			this->_val[0] = (v[0][2] + v[2][0]) / s;
			this->_val[1] = (v[1][2] + v[2][1]) / s;
			this->_val[2] = 0.25 * s;
		}
	}
	Quat::Quat(float x, float y, float z, float w)
	{
		_val[0] = x;
		_val[1] = y;
		_val[2] = z;
		_val[3] = w;
	}
	Quat		Quat::Identity(void)
	{
		return (Quat(0.0f, 0.0f, 0.0f, 1.0f));
	}
	Quat		Quat::Rotate(const Vec3 &up, const float angle)
	{
		Vec3	v = (Vec3)up * sinf(angle / 2.0f);

		return (Quat(v[0], v[1], v[2], cosf(angle / 2.0f)));
	}
	Quat		Quat::SetRotate(const Vec3 &angle)
	{
		return (
			Rotate(Vec3(0, 0, 1), angle[2]) *
			Rotate(Vec3(0, 1, 0), angle[0]) *
			Rotate(Vec3(1, 0, 0), angle[1])
		);
	}
	float		&Quat::operator[](const int i)
	{
		return (this->_val[i]);
	}
	const float	&Quat::operator[](const int i) const
	{
		return (this->_val[i]);
	}
	Quat 			&Quat::operator=(const Quat &v)
	{
		memcpy(this, &v, sizeof(Quat));
		return (*this);
	}
	bool 			Quat::operator==(const Quat &v)
	{
		return (
			_val[0] == v[0] +
			_val[1] == v[1] +
			_val[2] == v[2] +
			_val[3] == v[3]);
	}
	bool 			Quat::operator!=(const Quat &v)
	{
		return (!(*this == v));
	}
	Quat			Quat::operator+(const Quat &v)
	{
		return (Quat(
			_val[0] + v[0],
			_val[1] + v[1],
			_val[2] + v[2],
			_val[3] + v[3]));
	}
	Quat 			&Quat::operator+=(const Quat &v)
	{
		_val[0] += v[0];
		_val[1] += v[1];
		_val[2] += v[2];
		_val[3] += v[3];
		return (*this);
	}
	Quat			Quat::operator-(const Quat &v)
	{
		return (Quat(
			_val[0] - v[0],
			_val[1] - v[1],
			_val[2] - v[2],
			_val[3] - v[3]));
	}
	Quat 			&Quat::operator-=(const Quat &v)
	{
		_val[0] -= v[0];
		_val[1] -= v[1];
		_val[2] -= v[2];
		_val[3] -= v[3];
		return (*this);
	}
	Quat			Quat::operator*(const Quat &v)
	{
		return (Quat(
			_val[0] * v[3] + _val[1] * v[2] - _val[2] * v[1] + _val[3] * v[0],
			-_val[0] * v[2] + _val[1] * v[3] + _val[2] * v[0] + _val[3] * v[1],
			_val[0] * v[1] - _val[1] * v[0] + _val[2] * v[3] + _val[3] * v[2],
			-_val[0] * v[0] - _val[1] * v[1] - _val[2] * v[2] + _val[3] * v[3]
		));
	}
	Quat 			&Quat::operator*=(const Quat &v)
	{
		*this = *this * v;
		return (*this);
	}
	Vec3			Quat::operator*(const Vec3 &v)
	{
		Vec3	t;

		t = xyz().cross(v) * 2;
		return (t * _val[3] + xyz().cross(t) + v);
	}
	float			Quat::mulInner(const Quat &v)
	{
		return (
			_val[0] * v[0] +
			_val[1] * v[1] +
			_val[2] * v[2] +
			_val[3] * v[3]);
	}
	Quat			&Quat::scale(const float v)
	{
		_val[0] *= v;
		_val[1] *= v;
		_val[2] *= v;
		_val[3] *= v;
		return (*this);
	}
	Vec3			&Quat::xyz(void)
	{
		return (*(Vec3*)this);
	}

}

// void	quat_conj(t_quat r, t_quat q);
// void	quat_rotate(t_quat r, float angle, t_vec3 axis);

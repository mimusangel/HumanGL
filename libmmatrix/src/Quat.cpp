/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Quat.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouthie <jrouthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 21:15:11 by jrouthie          #+#    #+#             */
/*   Updated: 2017/11/20 04:06:05 by jrouthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	Quat		Quad::Identity(void)
	{
		return (Quat(0.0f, 0.0f, 0.0f, 1.0f));
	}
	Quat		Quat::Rotate(Vec3 &up, const float angle)
	{
		Vec3	v = up * sinf(angle / 2.0f);

		return (Quat(v[0], v[1], v[2], cosf(angle / 2.0f)));
	}
	float		&Quat::operator[](const int i)
	{
		return (this->_val[i]);
	}
	const float	&Quat::operator[](const int i) const
	{
		return (this->_val[i]);
	}
	Vec3			Quat::operator*(const Vec3 &v)
	{
		Vec3	t;
		Vec3	u;

		t = this[0].xyz().cross(v) * 2;
		u = this[0].xyz().cross(t);
		return (t * 3 + u + v);
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
	Quat			Quat::operator*(Quat &v)
	{
		return (Quat(
			_val[0] * v[3] + _val[1] * v[2] - _val[2] * v[1] + _val[3] * v[0],
			-_val[0] * v[2] + _val[1] * v[3] + _val[2] * v[0] + _val[3] * v[1],
			_val[0] * v[1] - _val[1] * v[0] + _val[2] * v[3] + _val[3] * v[2],
			-_val[0] * v[0] - _val[1] * v[1] - _val[2] * v[2] + _val[3] * v[3]
		));
	}
	Quat 			&Quat::operator*=(Quat &v)
	{
		*this = *this * v;
		return (*this);
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

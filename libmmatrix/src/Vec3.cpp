/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vec3.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouthie <jrouthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 19:23:03 by jrouthie          #+#    #+#             */
/*   Updated: 2017/11/20 02:40:37 by jrouthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mmatrix.hpp"
#include <cmath>
#include <cstring>

namespace mmatrix
{
	Vec3::Vec3(void)
	{
		this->_val[0] = 0;
		this->_val[1] = 0;
		this->_val[2] = 0;
	}
	Vec3::Vec3(float v)
	{
		this->_val[0] = v;
		this->_val[1] = v;
		this->_val[2] = v;
	}
	Vec3::Vec3(float x, float y, float z)
	{
		this->_val[0] = x;
		this->_val[1] = y;
		this->_val[2] = z;
	}
	Vec3::Vec3(const Vec2 &v, float z)
	{
		this->_val[0] = v[0];
		this->_val[1] = v[1];
		this->_val[2] = z;
	}
	Vec3::Vec3(const Vec3 &v)
	{
		this->_val[0] = v[0];
		this->_val[1] = v[1];
		this->_val[2] = v[2];
	}
	float		&Vec3::operator[](const int i)
	{
		return (this->_val[i]);
	}
	const float	&Vec3::operator[](const int i) const
	{
		return (this->_val[i]);
	}
	Vec3 		&Vec3::operator=(const Vec3 &v)
	{
		memcpy(this, &v, sizeof(Vec3));
		return (*this);
	}
	bool 		Vec3::operator==(const Vec3 &v)
	{
		return (
			this->_val[0] == v[0] &&
			this->_val[1] == v[1] &&
			this->_val[2] == v[2]);
	}
	Vec3		Vec3::operator+(const Vec3 &v)
	{
		return (Vec3(
			this->_val[0] + v[0],
			this->_val[1] + v[1],
			this->_val[2] + v[2]));
	}
	Vec3 		&Vec3::operator+=(const Vec3 &v)
	{
		this->_val[0] += v[0];
		this->_val[1] += v[1];
		this->_val[2] += v[2];
		return (*this);
	}
	Vec3		Vec3::operator-(const Vec3 &v)
	{
		return (Vec3(
			this->_val[0] - v[0],
			this->_val[1] - v[1],
			this->_val[2] - v[2]));
	}
	Vec3 		&Vec3::operator-=(const Vec3 &v)
	{
		this->_val[0] -= v[0];
		this->_val[1] -= v[1];
		this->_val[2] -= v[2];
		return (*this);
	}
	Vec3		Vec3::operator*(const Vec3 &v)
	{
		return (Vec3(
			this->_val[0] * v[0],
			this->_val[1] * v[1],
			this->_val[2] * v[2]));
	}
	Vec3 		&Vec3::operator*=(const Vec3 &v)
	{
		this->_val[0] *= v[0];
		this->_val[1] *= v[1];
		this->_val[2] *= v[2];
		return (*this);
	}
	Vec3		Vec3::operator/(const Vec3 &v)
	{
		return (Vec3(
			this->_val[0] / v[0],
			this->_val[1] / v[1],
			this->_val[2] / v[2]));
	}
	Vec3 		&Vec3::operator/=(const Vec3 &v)
	{
		this->_val[0] /= v[0];
		this->_val[1] /= v[1];
		this->_val[2] /= v[2];
		return (*this);
	}
	Vec3		Vec3::operator+(float v)
	{
		return (Vec3(
			this->_val[0] + v,
			this->_val[1] + v,
			this->_val[2] + v));
	}
	Vec3 		&Vec3::operator+=(float v)
	{
		this->_val[0] += v;
		this->_val[1] += v;
		this->_val[2] += v;
		return (*this);
	}
	Vec3		Vec3::operator-(float v)
	{
		return (Vec3(
			this->_val[0] - v,
			this->_val[1] - v,
			this->_val[2] - v));
	}
	Vec3 		&Vec3::operator-=(float v)
	{
		this->_val[0] -= v;
		this->_val[1] -= v;
		this->_val[2] -= v;
		return (*this);
	}
	Vec3		Vec3::operator*(float v)
	{
		return (Vec3(
			this->_val[0] * v,
			this->_val[1] * v,
			this->_val[2] * v));
	}
	Vec3 		&Vec3::operator*=(float v)
	{
		this->_val[0] *= v;
		this->_val[1] *= v;
		this->_val[2] *= v;
		return (*this);
	}
	Vec3		Vec3::operator/(float v)
	{
		return (Vec3(
			this->_val[0] / v,
			this->_val[1] / v,
			this->_val[2] / v));
	}
	Vec3 		&Vec3::operator/=(float v)
	{
		this->_val[0] /= v;
		this->_val[1] /= v;
		this->_val[2] /= v;
		return (*this);
	}
	float		Vec3::mulInner(const Vec3 &v)
	{
		return (
			_val[0] * v[0] +
			_val[1] * v[1] +
			_val[2] * v[2]);
	}
	Vec3		Vec3::cross(const Vec3 &v)
	{
		return (Vec3(
			this->_val[1] * v[2] - this->_val[2] * v[1],
			this->_val[2] * v[0] - this->_val[0] * v[2],
			this->_val[0] * v[1] - this->_val[1] * v[0]));
	}
	float		Vec3::dot(const Vec3 &v)
	{
		return (
			this->_val[0] * v[0] +
			this->_val[1] * v[1] +
			this->_val[2] * v[2]);
	}
	float		Vec3::length(void)
	{
		float	len =
			this->_val[0] * this->_val[0] +
			this->_val[1] * this->_val[1] +
			this->_val[2] * this->_val[2];
		if (len == 0.0f)
			return (0.0f);
		return (sqrtf(len));
	}
	Vec3 		&Vec3::normalise(void)
	{
		float	len = this->length();
		if (len != 0.0f)
		{
			len = 1.0f / len;
			this->_val[0] *= len;
			this->_val[1] *= len;
			this->_val[2] *= len;
		}
		return (*this);
	}
}

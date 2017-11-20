#include "mmatrix.hpp"
#include <cmath>
#include <cstring>

namespace mmatrix
{
	Vec4::Vec4(void)
	{
		this->_val[0] = 0;
		this->_val[1] = 0;
		this->_val[2] = 0;
		this->_val[3] = 0;
	}
	Vec4::Vec4(float v)
	{
		this->_val[0] = v;
		this->_val[1] = v;
		this->_val[2] = v;
		this->_val[3] = v;
	}
	Vec4::Vec4(float x, float y, float z, float w)
	{
		this->_val[0] = x;
		this->_val[1] = y;
		this->_val[2] = z;
		this->_val[3] = w;
	}
	Vec4::Vec4(const Vec3 &v, float w)
	{
		this->_val[0] = v[0];
		this->_val[1] = v[1];
		this->_val[2] = v[2];
		this->_val[3] = w;
	}
	Vec4::Vec4(const Vec4 &v)
	{
		this->_val[0] = v[0];
		this->_val[1] = v[1];
		this->_val[2] = v[2];
		this->_val[3] = v[3];
	}
	float		&Vec4::operator[](const int i)
	{
		return (this->_val[i]);
	}
	const float	&Vec4::operator[](const int i) const
	{
		return (this->_val[i]);
	}
	Vec4 		&Vec4::operator=(const Vec4 &v)
	{
		memcpy(this, &v, sizeof(Vec4));
		return (*this);
	}
	bool 		Vec4::operator==(const Vec4 &v)
	{
		return (
			this->_val[0] == v[0] &&
			this->_val[1] == v[1] &&
			this->_val[2] == v[2] &&
			this->_val[3] == v[3]);
	}
	Vec4		Vec4::operator+(const Vec4 &v)
	{
		return (Vec4(
			this->_val[0] + v[0],
			this->_val[1] + v[1],
			this->_val[2] + v[2],
			this->_val[3] + v[3]));
	}
	Vec4 		&Vec4::operator+=(const Vec4 &v)
	{
		this->_val[0] += v[0];
		this->_val[1] += v[1];
		this->_val[2] += v[2];
		this->_val[3] += v[3];
		return (*this);
	}
	Vec4		Vec4::operator-(const Vec4 &v)
	{
		return (Vec4(
			this->_val[0] - v[0],
			this->_val[1] - v[1],
			this->_val[2] - v[2],
			this->_val[3] - v[3]));
	}
	Vec4 		&Vec4::operator-=(const Vec4 &v)
	{
		this->_val[0] -= v[0];
		this->_val[1] -= v[1];
		this->_val[2] -= v[2];
		this->_val[3] -= v[3];
		return (*this);
	}
	Vec4		Vec4::operator*(const Vec4 &v)
	{
		return (Vec4(
			this->_val[0] * v[0],
			this->_val[1] * v[1],
			this->_val[2] * v[2],
			this->_val[3] * v[3]));
	}
	Vec4 		&Vec4::operator*=(const Vec4 &v)
	{
		this->_val[0] *= v[0];
		this->_val[1] *= v[1];
		this->_val[2] *= v[2];
		this->_val[3] *= v[3];
		return (*this);
	}
	Vec4		Vec4::operator/(const Vec4 &v)
	{
		return (Vec4(
			this->_val[0] / v[0],
			this->_val[1] / v[1],
			this->_val[2] / v[2],
			this->_val[3] / v[3]));
	}
	Vec4 		&Vec4::operator/=(const Vec4 &v)
	{
		this->_val[0] /= v[0];
		this->_val[1] /= v[1];
		this->_val[2] /= v[2];
		this->_val[3] /= v[3];
		return (*this);
	}
	Vec4		Vec4::operator+(float v)
	{
		return (Vec4(
			this->_val[0] + v,
			this->_val[1] + v,
			this->_val[2] + v,
			this->_val[3] + v));
	}
	Vec4 		&Vec4::operator+=(float v)
	{
		this->_val[0] += v;
		this->_val[1] += v;
		this->_val[2] += v;
		this->_val[3] += v;
		return (*this);
	}
	Vec4		Vec4::operator-(float v)
	{
		return (Vec4(
			this->_val[0] - v,
			this->_val[1] - v,
			this->_val[2] - v,
			this->_val[3] - v));
	}
	Vec4 		&Vec4::operator-=(float v)
	{
		this->_val[0] -= v;
		this->_val[1] -= v;
		this->_val[2] -= v;
		this->_val[3] -= v;
		return (*this);
	}
	Vec4		Vec4::operator*(float v)
	{
		return (Vec4(
			this->_val[0] * v,
			this->_val[1] * v,
			this->_val[2] * v,
			this->_val[3] * v));
	}
	Vec4 		&Vec4::operator*=(float v)
	{
		this->_val[0] *= v;
		this->_val[1] *= v;
		this->_val[2] *= v;
		this->_val[3] *= v;
		return (*this);
	}
	Vec4		Vec4::operator/(float v)
	{
		return (Vec4(
			this->_val[0] / v,
			this->_val[1] / v,
			this->_val[2] / v,
			this->_val[3] / v));
	}
	Vec4 		&Vec4::operator/=(float v)
	{
		this->_val[0] /= v;
		this->_val[1] /= v;
		this->_val[2] /= v;
		this->_val[3] /= v;
		return (*this);
	}
	float		Vec4::mulInner(const Vec4 &v)
	{
		return (
			_val[0] * v[0] +
			_val[1] * v[1] +
			_val[2] * v[2] +
			_val[3] * v[3]);
	}
	Vec4		Vec4::cross(const Vec4 &v)
	{
		return (Vec4(
			this->_val[1] * v[2] - this->_val[2] * v[1],
			this->_val[2] * v[0] - this->_val[0] * v[2],
			this->_val[0] * v[1] - this->_val[1] * v[0],
			1.0f));
	}
	float		Vec4::dot(const Vec4 &v)
	{
		return (
			this->_val[0] * v[0] +
			this->_val[1] * v[1] +
			this->_val[2] * v[2] +
			this->_val[3] * v[3]);
	}
	float		Vec4::length(void)
	{
		float	len =
			this->_val[0] * this->_val[0] +
			this->_val[1] * this->_val[1] +
			this->_val[2] * this->_val[2] +
			this->_val[3] * this->_val[3];
		if (len == 0.0f)
			return (0.0f);
		return (sqrtf(len));
	}
	Vec4 		&Vec4::normalise(void)
	{
		float	len = this->length();
		if (len != 0.0f)
		{
			len = 1.0f / len;
			this->_val[0] *= len;
			this->_val[1] *= len;
			this->_val[2] *= len;
			this->_val[3] *= len;
		}
		return (*this);
	}
	Vec3			&Vec4::xyz(void)
	{
		return (*(Vec3*)this);
	}
}

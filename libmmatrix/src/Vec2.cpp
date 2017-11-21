#include "mmatrix.hpp"
#include <cmath>
#include <cstring>

namespace mmatrix
{
	Vec2::Vec2(void)
	{
		this->_val[0] = 0;
		this->_val[1] = 0;
	}
	Vec2::Vec2(float v)
	{
		this->_val[0] = v;
		this->_val[1] = v;
	}
	Vec2::Vec2(float x, float y)
	{
		this->_val[0] = x;
		this->_val[1] = y;
	}
	Vec2::Vec2(const Vec2 &v)
	{
		this->_val[0] = v[0];
		this->_val[1] = v[1];
	}
	float		&Vec2::operator[](const int i)
	{
		return (this->_val[i]);
	}
	const float	&Vec2::operator[](const int i) const
	{
		return (this->_val[i]);
	}
	Vec2 		&Vec2::operator=(const Vec2 &v)
	{
		memcpy(this, &v, sizeof(Vec2));
		return (*this);
	}
	bool 		Vec2::operator==(const Vec2 &v)
	{
		return (
			this->_val[0] == v[0] &&
			this->_val[1] == v[1]);
	}
	bool 		Vec2::operator!=(const Vec2 &v)
	{
		return (!(*this == v));
	}
	Vec2		Vec2::operator+(const Vec2 &v)
	{
		return (Vec2(this->_val[0] + v[0], this->_val[1] + v[1]));
	}
	Vec2 		&Vec2::operator+=(const Vec2 &v)
	{
		this->_val[0] += v[0];
		this->_val[1] += v[1];
		return (*this);
	}
	Vec2		Vec2::operator-(const Vec2 &v)
	{
		return (Vec2(this->_val[0] - v[0], this->_val[1] - v[1]));
	}
	Vec2 		&Vec2::operator-=(const Vec2 &v)
	{
		this->_val[0] -= v[0];
		this->_val[1] -= v[1];
		return (*this);
	}
	Vec2		Vec2::operator*(const Vec2 &v)
	{
		return (Vec2(this->_val[0] * v[0], this->_val[1] * v[1]));
	}
	Vec2 		&Vec2::operator*=(const Vec2 &v)
	{
		this->_val[0] *= v[0];
		this->_val[1] *= v[1];
		return (*this);
	}
	Vec2		Vec2::operator/(const Vec2 &v)
	{
		return (Vec2(this->_val[0] / v[0], this->_val[1] / v[1]));
	}
	Vec2 		&Vec2::operator/=(const Vec2 &v)
	{
		this->_val[0] /= v[0];
		this->_val[1] /= v[1];
		return (*this);
	}
	Vec2		Vec2::operator+(float v)
	{
		return (Vec2(this->_val[0] + v, this->_val[1] + v));
	}
	Vec2 		&Vec2::operator+=(float v)
	{
		this->_val[0] += v;
		this->_val[1] += v;
		return (*this);
	}
	Vec2		Vec2::operator-(float v)
	{
		return (Vec2(this->_val[0] - v, this->_val[1] - v));
	}
	Vec2 		&Vec2::operator-=(float v)
	{
		this->_val[0] -= v;
		this->_val[1] -= v;
		return (*this);
	}
	Vec2		Vec2::operator*(float v)
	{
		return (Vec2(this->_val[0] * v, this->_val[1] * v));
	}
	Vec2 		&Vec2::operator*=(float v)
	{
		this->_val[0] *= v;
		this->_val[1] *= v;
		return (*this);
	}
	Vec2		Vec2::operator/(float v)
	{
		return (Vec2(this->_val[0] / v, this->_val[1] / v));
	}
	Vec2 		&Vec2::operator/=(float v)
	{
		this->_val[0] /= v;
		this->_val[1] /= v;
		return (*this);
	}
	float		Vec2::dot(const Vec2 &v)
	{
		return (this->_val[0] * v[0] + this->_val[1] * v[1]);
	}
	float		Vec2::length(void)
	{
		float	len = this->_val[0] * this->_val[0] +
			this->_val[1] * this->_val[1];
		if (len == 0.0f)
			return (0.0f);
		return (sqrtf(len));
	}
	Vec2 		&Vec2::normalise(void)
	{
		float	len = this->length();
		if (len != 0.0f)
		{
			len = 1.0f / len;
			this->_val[0] *= len;
			this->_val[1] *= len;
		}
		return (*this);
	}
}

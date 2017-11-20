/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mat4x4.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouthie <jrouthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 21:15:11 by jrouthie          #+#    #+#             */
/*   Updated: 2017/11/20 01:57:22 by jrouthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mmatrix.hpp"
#include <cmath>
#include <cstring>

namespace mmatrix
{
	Mat4x4::Mat4x4(void)
	{
		memset(this->_val, 0, sizeof(float) * 4 * 4);
	}
	Mat4x4::Mat4x4(float v)
	{
		for (int x = 0; x < 4; x++)
			for (int y = 0; y < 4; y++)
				this->_val[x][y] = v;
	}
	Mat4x4::Mat4x4(float v[4][4])
	{
		memcpy(this->_val, v, sizeof(float) * 4 * 4);
	}
	Mat4x4::Mat4x4(const Mat4x4 &v)
	{
		for (int x = 0; x < 4; x++)
			for (int y = 0; y < 4; y++)
				this->_val[x][y] = v[x][y];
	}
	Mat4x4	Mat4x4::identity(void)
	{
		return (Mat4x4((float[4][4]){
			{1, 0, 0, 0},
			{0, 1, 0, 0},
			{0, 0, 1, 0},
			{0, 0, 0, 1}}));
	}
	Vec4			&Mat4x4::operator[](const int i)
	{
		return (this->_val[i]);
	}
	const Vec4		&Mat4x4::operator[](const int i) const
	{
		return (this->_val[i]);
	}
	Mat4x4 		&Mat4x4::operator=(const Mat4x4 &v)
	{
		memcpy(this, &v, sizeof(Mat4x4));
		return (*this);
	}
	bool 		Mat4x4::operator==(const Mat4x4 &v)
	{
		return (
			this->_val[0] == v[0] &&
			this->_val[1] == v[1] &&
			this->_val[2] == v[2] &&
			this->_val[3] == v[3]);
	}
	Mat4x4			Mat4x4::operator+(const Mat4x4 &v)
	{
		return (Mat4x4((float[4][4]){
			{this->_val[0][0] + v[0][0], this->_val[0][1] + v[0][1],
				this->_val[0][2] + v[0][2], this->_val[0][3] + v[0][3]},
			{this->_val[1][0] + v[1][0], this->_val[1][1] + v[1][1],
				this->_val[1][2] + v[1][2], this->_val[1][3] + v[1][3]},
			{this->_val[2][0] + v[2][0], this->_val[2][1] + v[2][1],
				this->_val[2][2] + v[2][2], this->_val[2][3] + v[2][3]},
			{this->_val[3][0] + v[3][0], this->_val[3][1] + v[3][1],
				this->_val[3][2] + v[3][2], this->_val[3][3] + v[3][3]}
		}));
	}
	Mat4x4 			&Mat4x4::operator+=(const Mat4x4 &v)
	{
		this->_val[0][0] += v[0][0];
		this->_val[0][1] += v[0][1];
		this->_val[0][2] += v[0][2];
		this->_val[0][3] += v[0][3];
		this->_val[1][0] += v[1][0];
		this->_val[1][1] += v[1][1];
		this->_val[1][2] += v[1][2];
		this->_val[1][3] += v[1][3];
		this->_val[2][0] += v[2][0];
		this->_val[2][1] += v[2][1];
		this->_val[2][2] += v[2][2];
		this->_val[2][3] += v[2][3];
		this->_val[3][0] += v[3][0];
		this->_val[3][1] += v[3][1];
		this->_val[3][2] += v[3][2];
		this->_val[3][3] += v[3][3];
		return (*this);
	}
	Mat4x4			Mat4x4::operator-(const Mat4x4 &v)
	{
		return (Mat4x4((float[4][4]){
			{this->_val[0][0] - v[0][0], this->_val[0][1] - v[0][1],
				this->_val[0][2] - v[0][2], this->_val[0][3] - v[0][3]},
			{this->_val[1][0] - v[1][0], this->_val[1][1] - v[1][1],
				this->_val[1][2] - v[1][2], this->_val[1][3] - v[1][3]},
			{this->_val[2][0] - v[2][0], this->_val[2][1] - v[2][1],
				this->_val[2][2] - v[2][2], this->_val[2][3] - v[2][3]},
			{this->_val[3][0] - v[3][0], this->_val[3][1] - v[3][1],
				this->_val[3][2] - v[3][2], this->_val[3][3] - v[3][3]}
		}));
	}
	Mat4x4 			&Mat4x4::operator-=(const Mat4x4 &v)
	{
		this->_val[0][0] -= v[0][0];
		this->_val[0][1] -= v[0][1];
		this->_val[0][2] -= v[0][2];
		this->_val[0][3] -= v[0][3];
		this->_val[1][0] -= v[1][0];
		this->_val[1][1] -= v[1][1];
		this->_val[1][2] -= v[1][2];
		this->_val[1][3] -= v[1][3];
		this->_val[2][0] -= v[2][0];
		this->_val[2][1] -= v[2][1];
		this->_val[2][2] -= v[2][2];
		this->_val[2][3] -= v[2][3];
		this->_val[3][0] -= v[3][0];
		this->_val[3][1] -= v[3][1];
		this->_val[3][2] -= v[3][2];
		this->_val[3][3] -= v[3][3];
		return (*this);
	}
	Mat4x4			Mat4x4::operator*(const Mat4x4 &v)
	{
		Mat4x4	mat;

		for (int c = 0; c < 4; c++)
			for (int r = 0; r < 4; r++)
				for (int k = 0; k < 4; k++)
					mat[c][r] += this->_val[k][r] * v[c][k];
		return (mat);
	}
	Mat4x4 			&Mat4x4::operator*=(const Mat4x4 &v)
	{
		for (int c = 0; c < 4; c++)
			for (int r = 0; r < 4; r++)
				for (int k = 0; k < 4; k++)
					this->_val[k][r] *= v[c][k];
		return (*this);
	}
	Mat4x4			Mat4x4::operator*(Quad &v)
	{
		Mat4x4	mat;

		mat[0] = Vec4(v * _val[0].xyz(), 0);
		mat[1] = Vec4(v * _val[0].xyz(), 0);
		mat[2] = Vec4(v * _val[0].xyz(), 0);
		mat[3] = Vec4(0.0f, 0.0f, 0.0f, 1.0f);
		return (mat);
	}
	Mat4x4 			&Mat4x4::operator*=(Quad &v)
	{
		*this = *this * v;
		return (*this);
	}
	float			Mat4x4::dot(const Mat4x4 &v)
	{
		float	d = 0;

		for (int x = 0; x < 4; x++)
			for (int y = 0; y < 4; y++)
				d += this->_val[x][y] * v[x][y];
		return (d);
	}
	float			Mat4x4::length(void)
	{
		float	l = 0;

		for (int x = 0; x < 4; x++)
			for (int y = 0; y < 4; y++)
				l += this->_val[x][y] * this->_val[x][y];
		if (l == 0.0f)
			return (0.0f);
		return (sqrtf(l));
	}
	Mat4x4			&Mat4x4::scale(const float v)
	{
		for (int x = 0; x < 4; x++)
			for (int y = 0; y < 4; y++)
				this->_val[x][y] *= v;
		return (*this);
	}
	Mat4x4			&Mat4x4::scale_aniso(const float v[3])
	{
		for (int x = 0; x < 3; x++)
			for (int y = 0; y < 4; y++)
				this->_val[x][y] *= v[x];
		return (*this);
	}
	Mat4x4			&Mat4x4::rotate(const Vec3 &up, const float angle)
	{
		float	s;
		float	c;
		Mat4x4	t;
		Mat4x4	ss;
		Mat4x4	cc;

		s = sinf(angle);
		c = cosf(angle);
		t = Mat4x4((float[4][4]){
				{up[0] * up[0], up[0] * up[1], up[0] * up[2], 0},
				{up[1] * up[0], up[1] * up[1], up[1] * up[2], 0},
				{up[2] * up[0], up[2] * up[1], up[2] * up[2], 0},
				{0, 0, 0, 0}});
		ss = Mat4x4((float[4][4]){
				{0, up[2] * s, -up[1] * s, 0},
				{-up[2] * s, 0, up[0] * s, 0},
				{up[1] * s, -up[0] * s, 0, 0},
				{0, 0, 0, 0}});
		cc = identity() - t;
		cc.scale(c);
		t += cc;
		t += ss;
		t[3][3] = 1.0f;
		*this *= t;
		return (*this);
	}
	/*Mat4x4			&Mat4x4::rotate_x(const float angle);
	Mat4x4			&Mat4x4::rotate_y(const float angle);
	Mat4x4			&Mat4x4::rotate_z(const float angle);
	Mat4x4			&Mat4x4::set_translate(const Vec3 &v);
	Mat4x4			&Mat4x4::translate(const Vec3 &v);
	Mat4x4			&Mat4x4::translate_in_place(const Vec3 &v);
	Mat4x4 			Mat4x4::transpose();*/
}

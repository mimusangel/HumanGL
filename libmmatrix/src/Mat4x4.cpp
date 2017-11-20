/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mat4x4.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouthie <jrouthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 21:15:11 by jrouthie          #+#    #+#             */
/*   Updated: 2017/11/20 03:57:56 by jrouthie         ###   ########.fr       */
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
	Mat4x4::Mat4x4(const Quat &v)
	{
		const float	sqw = v[3] * v[3];
		const float	sqx = v[0] * v[0];
		const float	sqy = v[1] * v[1];
		const float	sqz = v[2] * v[2];
		const float	invs = 1.0f / (sqw + sqx + sqy + sqz);
		float		tmp1;
		float		tmp2;

		tmp1 = v[0] * v[1];
		tmp2 = v[2] * v[3];
		_val[0][0] = (sqx - sqy - sqz + sqw) * invs;
		_val[1][1] = (-sqx + sqy - sqz + sqw) * invs;
		_val[2][2] = (-sqx - sqy + sqz + sqw) * invs;
		tmp1 = v[0] * v[1];
		tmp2 = v[2] * v[3];
		_val[1][0] = 2.0 * (tmp1 + tmp2) * invs;
		_val[0][1] = 2.0 * (tmp1 - tmp2) * invs;
		tmp1 = v[0] * v[2];
		tmp2 = v[1] * v[3];
		_val[2][0] = 2.0 * (tmp1 - tmp2) * invs;
		_val[0][2] = 2.0 * (tmp1 + tmp2) * invs;
		tmp1 = v[1] * v[2];
		tmp2 = v[0] * v[3];
		_val[2][1] = 2.0 * (tmp1 + tmp2) * invs;
		_val[1][2] = 2.0 * (tmp1 - tmp2) * invs;
		_val[0][3] = 0.0f;
		_val[1][3] = 0.0f;
		_val[2][3] = 0.0f;
		_val[3][0] = 0.0f;
		_val[3][1] = 0.0f;
		_val[3][2] = 0.0f;
		_val[3][3] = 0.0f;
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
	Mat4x4	Mat4x4::fromEuler(Vec3 v)
	{
		float	t[6];

		t[0] = cosf(v[1]);
		t[1] = sinf(v[1]);
		t[2] = cosf(v[0]);
		t[3] = sinf(v[0]);
		t[4] = cosf(v[2]);
		t[5] = sinf(v[2]);
		return (Mat4x4((float[4][4]){
			{t[0] * t[2], t[1] * t[5] - t[0] * t[3] * t[4],
				t[0] * t[3] * t[5] + t[1] * t[4], 0},
			{t[3], t[2] * t[4], -t[2] * t[5], 0},
			{-t[1] * t[2], t[1] * t[3] * t[4] + t[0] * t[5],
				-t[1] * t[3] * t[5] + t[0] * t[4], 0},
			{0, 0, 0, 1}
		}));
	}
	Mat4x4	Mat4x4::frustum(float v[6])
	{
		return (Mat4x4((float[4][4]){
			{2.0f * v[4] / (v[1] - v[0]), 0.0f, 0.0f, 0.0f},
			{2.0f * v[4] / (v[3] - v[2]), 0.0f, 0.0f, 0.0f},
			{(v[1] + v[0]) / (v[1] - v[0]), (v[3] + v[2]) / (v[3] - v[2]),
				-(v[5] + v[4]) / (v[5] - v[4]), -1.0f},
			{-2.0f * (v[5] * v[4]) / (v[5] - v[4]), 0.0f, 0.0f, 0.0f}
		}));
	}
	Mat4x4	Mat4x4::lookAt(const Vec3 &eye, Vec3 &center,
		const Vec3 &up)
	{
		Vec3	f = center - eye;
		f.normalise();
		Vec3	s = f.cross(up);
		s.normalise();
		Vec3	t = s.cross(f);
		Mat4x4	mat((float[4][4]){
			{s[0], t[0], -f[0], 0.0f},
			{s[1], t[1], -f[1], 0.0f},
			{s[2], t[2], -f[2], 0.0f},
			{0.0f, 0.0f, 0.0f, 1.0f}
		});
		return (mat.translate_in_place(Vec3(-eye[0], -eye[1], -eye[2])));
	}
	Mat4x4	Mat4x4::ortho(float v[6])
	{
		return (Mat4x4((float[4][4]){
			{2.0f / (v[1] - v[0]), 0.0f, 0.0f, 0.0f},
			{2.0f / (v[3] - v[2]), 0.0f, 0.0f, 0.0f},
			{-2.0f / (v[5] - v[4]), 0.0f, 0.0f, 0.0f},
			{-(v[1] + v[0]) / (v[1] - v[0]), -(v[3] + v[2]) / (v[3] - v[2]),
				-(v[5] + v[4]) / (v[5] - v[4]), 1.0f}
		}));
	}
	Mat4x4	Mat4x4::perspective(const float y_fov, const float aspect,
		const float near, const float far)
	{
		const float	a = 1.0f / tanf(y_fov / 2.0f);

		return (Mat4x4((float[4][4]){
			{a / aspect, 0.0f, 0.0f, 0.0f},
			{0.0f, a, 0.0f, 0.0f},
			{0.0f, 0.0f, -((far + near) / (far - near)), -1.0f},
			{0.0f, 0.0f, -((2.0f * far * near) / (far - near)), 0.0f}
		}));
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
	Mat4x4			Mat4x4::operator*(Quat &v)
	{
		Mat4x4	mat;

		mat[0] = Vec4(v * _val[0].xyz(), 0);
		mat[1] = Vec4(v * _val[0].xyz(), 0);
		mat[2] = Vec4(v * _val[0].xyz(), 0);
		mat[3] = Vec4(0.0f, 0.0f, 0.0f, 1.0f);
		return (mat);
	}
	Mat4x4 			&Mat4x4::operator*=(Quat &v)
	{
		*this = *this * v;
		return (*this);
	}
	Vec4			Mat4x4::row(const int i)
	{
		return (Vec4(
			_val[0][i],
			_val[1][i],
			_val[2][i],
			_val[3][i]));
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
	Mat4x4			&Mat4x4::rotate_x(const float angle)
	{
		const float		s = sinf(angle);
		const float		c = cosf(angle);

		*this *= Mat4x4((float[4][4]){
			{1.0f, 0.0f, 0.0f, 0.0f},
			{0.0f, c, s, 0.0f},
			{0.0f, -s, c, 0.0f},
			{0.0f, 0.0f, 0.0f, 1.0f}
		});
		return (*this);
	}
	Mat4x4			&Mat4x4::rotate_y(const float angle)
	{
		const float		s = sinf(angle);
		const float		c = cosf(angle);

		*this *= Mat4x4((float[4][4]){
			{c, 0.0f, s, 0.0f},
			{0.0f, 1.0f, 0.0f, 0.0f},
			{-s, 0.0f, c, 0.0f},
			{0.0f, 0.0f, 0.0f, 1.0f}
		});
		return (*this);
	}
	Mat4x4			&Mat4x4::rotate_z(const float angle)
	{
		const float		s = sinf(angle);
		const float		c = cosf(angle);

		*this *= Mat4x4((float[4][4]){
			{c, s, 0.0f, 0.0f},
			{-s, c, 0.0f, 0.0f},
			{0.0f, 0.0f, 1.0f, 0.0f},
			{0.0f, 0.0f, 0.0f, 1.0f}
		});
		return (*this);
	}
	Mat4x4			&Mat4x4::set_translate(const Vec3 &v)
	{
		_val[3][0] = v[0];
		_val[3][1] = v[1];
		_val[3][2] = v[2];
		return (*this);
	}
	Mat4x4			Mat4x4::translate(const Vec3 &v)
	{
		Mat4x4	mat = identity();

		mat[3][0] = v[0];
		mat[3][1] = v[1];
		mat[3][2] = v[2];
		return (mat);
	}
	Mat4x4			&Mat4x4::translate_in_place(const Vec3 &v)
	{
		Vec4	t(v, 0);

		for (int i = 0; i < 4; i++)
			_val[3][i] += row(i).mulInner(t);
		return (*this);
	}
	Mat4x4 			Mat4x4::transpose()
	{
		Mat4x4	out;

		for (int x = 0; x < 4; x++)
			for (int y = 0; y < 4; y++)
				out[x][y] = _val[y][x];
		return (out);
	}
}

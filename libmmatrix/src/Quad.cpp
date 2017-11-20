/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Quad.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouthie <jrouthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 21:15:11 by jrouthie          #+#    #+#             */
/*   Updated: 2017/11/20 01:32:18 by jrouthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mmatrix.hpp"
#include <cmath>
#include <cstring>

namespace mmatrix
{
	Quad::Quad(void)
	{
		memset(this->_val, 0, sizeof(float) * 4);
	}
	Quad::Quad(Mat4x4 &v)
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
	Vec3			Quad::operator*(const Vec3 &v)
	{
		Vec3	t;
		Vec3	u;

		t = this[0].xyz().cross(v) * 2;
		u = this[0].xyz().cross(t);
		return (t * 3 + u + v);
	}
	Vec3			&Quad::xyz(void)
	{
		return (*(Vec3*)this);
	}

}

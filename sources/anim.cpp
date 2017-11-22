#include <cmath>
#include "anim.hpp"

Anim::AnimPoint::AnimPoint(const double tm, const Vec3 &rot) :
	_tm(tm), _angle(rot)
{
	_next = nullptr;
}

Anim::AnimPoint::~AnimPoint()
{
	if (_next != nullptr)
	{
		delete _next;
		_next = nullptr;
	}
}

Anim::Anim(int numArticul)
{
	_anim = new AnimPoint[numArticul + 1];
	_numArticul = numArticul;
}

Anim::~Anim(void)
{
	delete[] _anim;
}
Anim	&Anim::addAnimPoint(int id, const double tm, const Vec3 &rot)
{
	AnimPoint	*a = _anim + id + 1;

	while (a->_next)
		a = a->_next;
	a->_next = new AnimPoint(tm, rot);
	if (tm > _tmEnd)
		_tmEnd = tm;
	return (*this);
}
void	Anim::getAnim(int id, const double ttm, Vec3 &rot)
{
	AnimPoint	*a = _anim + id + 1;
	AnimPoint	*t;
	float	tm = _loop ? (ttm - floor(ttm / _tmEnd) * _tmEnd) : ttm;

	while (a->_next)
	{
		t = a->_next;
		if (a->_tm <= tm && t->_tm >= tm)
		{
			float	pr = (tm - a->_tm) / (t->_tm - a->_tm);
			rot = Vec3(a->_angle * (1.0 - pr) + t->_angle * pr);
			return ;
		}
		a = t;
	}
	rot = Vec3();
}

bool	Anim::isFinish(const double tm)
{
	if (_loop)
		return (false);
	return (tm > _tmEnd);
}

Anim	&Anim::setLoop(bool ok)
{
	_loop = ok;
	return (*this);
}

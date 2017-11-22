
#include "anim.hpp"

Anim::AnimPoint::AnimPoint(const double tm, const Vec3 &rot, const Vec3 &pos) :
	_tm(tm), _angle(rot), _pos(pos)
{
	_next = nullptr;
}


Anim::Anim(int numArticul)
{
	_anim = new AnimPoint[numArticul];
	_numArticul = numArticul;
}
Anim::~Anim(void)
{
	AnimPoint	*a;
	AnimPoint	*t;

	for (int i = 0; i < _numArticul; i++)
	{
		a = _anim + i;
		while (a->_next)
		{
			t = a;
			a = a->_next;
			delete t;
		}
	}
	delete _anim;
}
void	Anim::addAnimPoint(int id, const double tm, const Vec3 &rot, const Vec3 &pos)
{
	AnimPoint	*a = _anim + id;

	while (a->_next)
		a = a->_next;
	a->_next = new AnimPoint(tm, rot, pos);
}
void	Anim::getAnim(int id, const double tm, Vec3 &rot, Vec3 &pos)
{
	AnimPoint	*a = _anim + id;
	AnimPoint	*t;

	while (a->_next)
	{
		t = a->_next;
		if (a->_tm <= tm && t->_tm >= tm)
		{
			float	pr = (tm - a->_tm) / (t->_tm - a->_tm);
			rot = Vec3(a->_angle * pr + t->_angle * (1.0f - pr));
			pos = Vec3(a->_pos * pr + t->_pos * (1.0f - pr));
		}
		a = t;
	}
}

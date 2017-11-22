#ifndef ANIM_HPP
# define ANIM_HPP

# include "humangl.hpp"

using namespace mmatrix;

class Anim {
private:
	class	AnimPoint
	{
	public:
		double		_tm;
		Vec3		_angle;
		Vec3		_pos;
		AnimPoint	*_next;
		AnimPoint(const double tm = 0.0, const Vec3 &rot = Vec3(), const Vec3 &pos = Vec3());
	};
	AnimPoint	*_anim[];
	int			_numArticul;
	double		_start;
public:
	Anim(int numArticul);
	~Anim(void);
	void	addAnimPoint(int id, const double tm, const Vec3 &rot = Vec3(), const Vec3 &pos = Vec3());
	void	getAnim(int id, const double tm, Vec3 &rot, Vec3 &pos);
	// void	update(double tm, Anim &anim);
};

#endif

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
		AnimPoint	*_next;
		AnimPoint(const double tm = 0.0, const Vec3 &rot = Vec3());
		~AnimPoint();
	};
	AnimPoint	*_anim;
	int			_numArticul;
	double		_tmEnd;
	bool		_loop;
public:
	Anim(int numArticul);
	~Anim(void);
	void	addAnimPoint(int id, const double tm, const Vec3 &rot = Vec3());
	void	getAnim(int id, const double tm, Vec3 &rot);
	bool	isFinish(const double tm);
	void	setLoop(bool ok);
};

#endif

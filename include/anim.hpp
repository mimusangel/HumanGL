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
	Anim	&addAnimPoint(int id, const double tm, const Vec3 &rot = Vec3());
	void	getAnim(int id, const double tm, Vec3 &rot);
	bool	isFinish(const double tm);
	int		getNumArticul(void);
	Anim	&setLoop(bool ok);
};

class AnimManager {
public:
	static Anim	loadIdle(float speed = 1.0f);
	static Anim	loadWalk(float speed = 1.0f);
	static Anim	loadRun(float speed = 1.0f);
	static Anim	loadJump(float speed = 1.0f);
	static Anim	loadCrouch(float speed = 1.0f);
	static Anim	loadMasturbate(float speed = 1.0f);
	static Anim loadNeo(float speed = 1.0f);
	static Anim loadCloClo(float speed = 1.0f);
};

#endif

#ifndef HUMAN_HPP
#define HUMAN_HPP

# include "humangl.hpp"
# include "cube.hpp"
# include "shaders.hpp"
# include "anim.hpp"

# define HUMAN_BODY				Vec3(0.25f, 0.375f, 0.125f)
# define HUMAN_HEAD				Vec3(0.25f)
# define HUMAN_LEFT_ARM_UP		Vec3(0.1248f, 0.1875f, 0.1248f)
# define HUMAN_LEFT_ARM_DOWN	Vec3(0.1246f, 0.1875f, 0.1246f)
# define HUMAN_LEFT_FOOT_UP		Vec3(0.1248f, 0.1875f, 0.1248f)
# define HUMAN_LEFT_FOOT_DOWN	Vec3(0.1246f, 0.1875f, 0.1246f)
# define HUMAN_RIGHT_ARM_UP		Vec3(0.1248f, 0.1875f, 0.1248f)
# define HUMAN_RIGHT_ARM_DOWN	Vec3(0.1246f, 0.1875f, 0.1246f)
# define HUMAN_RIGHT_FOOT_UP	Vec3(0.1248f, 0.1875f, 0.1248f)
# define HUMAN_RIGHT_FOOT_DOWN	Vec3(0.1246f, 0.1875f, 0.1246f)

class Human {
private:
	Cube _parts[10];
	Vec3 _colors[10];
	Anim	*_anim;
	double	_animStart;
public:
	Human(void);
	void		render(Shaders &shader);
	void 		update(float delta);
	void 		setAnim(Anim *anim);
};

#endif

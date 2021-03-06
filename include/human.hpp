#ifndef HUMAN_HPP
#define HUMAN_HPP

# include "humangl.hpp"
# include "cube.hpp"
# include "shaders.hpp"
# include "anim.hpp"
# define HUMAN_PART_C			15
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
# define HUMAN_EYES				Vec3(0.05f)
# define HUMAN_HAIR				Vec3(0.05f, 0.2f, 0.15f)
# define HUMAN_GIRL				Vec3(0.20f, 0.1f, 0.1f)
# define HUMAN_PENIS			Vec3(0.04f, 0.04f, 0.18f)

class Human {
private:
	Cube _parts[HUMAN_PART_C];
	Vec3 _colors[HUMAN_PART_C];
	Anim	*_anim;
	double	_animStart;
	bool	cloth;
	bool	girl;
public:
	Human(void);
	void		render(Shaders &shader);
	void 		update(float delta);
	void 		setAnim(Anim *anim);
	void		switchCloth(void);
	void		switchGender(void);
	Cube		&getParts(int i);
};

#endif

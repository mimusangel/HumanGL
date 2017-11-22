#include "human.hpp"
using namespace mmatrix;

Human::Human(void)
{
	_parts[0] = Cube(Vec3(0, 0.375f, 0),Vec3(),	Vec3(0.0f, 0.5f, 0.0f),	HUMAN_BODY);
	_parts[1] = Cube(Vec3(0, 1, 0),		Vec3(), Vec3(0.0f, 0.5f, 0.0f),	HUMAN_HEAD).setParent(_parts);
	_parts[2] = Cube(Vec3(-0.5, 1, 0),	Vec3(),	Vec3(-0.5, -0.5, 0.f),	HUMAN_LEFT_ARM_UP).setParent(_parts);
	_parts[3] = Cube(Vec3(-0.5, -1, 0),	Vec3(),	Vec3(0, -0.5, 0), 		HUMAN_LEFT_ARM_DOWN).setParent(_parts + 2);
	_parts[4] = Cube(Vec3(-0.25, 0, 0),	Vec3(),	Vec3(0, -0.5, 0.f),		HUMAN_LEFT_FOOT_UP).setParent(_parts);
	_parts[5] = Cube(Vec3(0, -1, 0),	Vec3(),	Vec3(0, -0.5, 0),		HUMAN_LEFT_FOOT_DOWN).setParent(_parts + 4);
	_parts[6] = Cube(Vec3(0.5, 1, 0),	Vec3(),	Vec3(0.5, -0.5, 0.f),	HUMAN_RIGHT_ARM_UP).setParent(_parts);
	_parts[7] = Cube(Vec3(0.5, -1, 0),	Vec3(),	Vec3(0, -0.5, 0),		HUMAN_RIGHT_ARM_DOWN).setParent(_parts + 6);
	_parts[8] = Cube(Vec3(0.25, 0, 0),	Vec3(),	Vec3(0, -0.5, 0.f),		HUMAN_RIGHT_FOOT_UP).setParent(_parts);
	_parts[9] = Cube(Vec3(0, -1, 0),	Vec3(),	Vec3(0, -0.5, 0),		HUMAN_RIGHT_FOOT_DOWN).setParent(_parts + 8);
	_parts[10] = Cube(Vec3(0.25, 0.5, 0.5),	Vec3(),	Vec3(0, 0, 0),		HUMAN_EYES).setParent(_parts + 1);
	_parts[11] = Cube(Vec3(-0.25, 0.5, 0.5),	Vec3(),	Vec3(0, 0, 0),	HUMAN_EYES).setParent(_parts + 1);
	_parts[12] = Cube(Vec3(0, 1, 0.f),	Vec3(),	Vec3(0, 0, 0),			HUMAN_HAIR).setParent(_parts + 1);

	_colors[0] = Vec3(0.5f, 0.f, 0.f);
	_colors[1] = Vec3(0.9960784314f, 0.7647058824f, 0.6745098039f);
	_colors[2] = Vec3(0.5f, 0.f, 0.f);
	_colors[3] = Vec3(0.9960784314f, 0.7647058824f, 0.6745098039f);
	_colors[4] = Vec3(0.f, 0.f, 0.5f);
	_colors[5] = Vec3(0.9960784314f, 0.7647058824f, 0.6745098039f);
	_colors[6] = Vec3(0.5f, 0.f, 0.f);
	_colors[7] = Vec3(0.9960784314f, 0.7647058824f, 0.6745098039f);
	_colors[8] = Vec3(0.f, 0.f, 0.5f);
	_colors[9] = Vec3(0.9960784314f, 0.7647058824f, 0.6745098039f);
	_colors[10] = Vec3(1.f);
	_colors[11] = Vec3(1.f);
	_colors[12] = Vec3(0.32f, 0.24f, 0.196f);
}

void		Human::render(Shaders &shader)
{
	for (size_t i = 0; i < HUMAN_PART_C; i++)
		_parts[i].render(shader, _colors[i]);
}

void 		Human::update(float delta)
{
	const double	tm = delta - _animStart;

	if (_anim)
	{
		_anim->getAnim(-1, tm, _parts[0].getPos());
		for (int i = 0; i < _anim->getNumArticul(); i++)
		{
			_anim->getAnim(i, tm, _parts[i].getRot());
		}
		if (_anim->isFinish(tm))
			_anim = nullptr;
	}
}

void 		Human::setAnim(Anim *anim)
{
	_anim = anim;
	_animStart = glfwGetTime();
	if (_anim == nullptr)
	{
		for (size_t i = 0; i < HUMAN_PART_C; i++)
			_parts[i].getRot() = Vec3();
		_parts[0].getPos() = Vec3();
	}
}

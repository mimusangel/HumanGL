#include "human.hpp"
using namespace mmatrix;

Human::Human(void)
{
	_parts[0] = Cube(Vec3(0, 0.375f, 0),Vec3(),	Vec3(0.0f, 0.5f, 0.0f),	Vec3(0.25f, 0.375f, 0.125f));
	_parts[1] = Cube(Vec3(0, 1, 0),		Vec3(), Vec3(0.0f, 0.5f, 0.0f),	Vec3(0.25f)).setParent(_parts);
	_parts[2] = Cube(Vec3(-0.5, 1, 0),	Vec3(),	Vec3(-0.5, -0.5, 0.f),	Vec3(0.1249f, 0.1875f, 0.1249f)).setParent(_parts);
	_parts[3] = Cube(Vec3(-0.5, -1, 0),	Vec3(),	Vec3(0, -0.5, 0), 		Vec3(0.1249f, 0.1875f, 0.1249f)).setParent(_parts + 2);
	_parts[4] = Cube(Vec3(-0.25, 0, 0),	Vec3(),	Vec3(0, -0.5, 0.f),		Vec3(0.1249f, 0.1875f, 0.1249f)).setParent(_parts);
	_parts[5] = Cube(Vec3(0, -1, 0),	Vec3(),	Vec3(0, -0.5, 0),		Vec3(0.1249f, 0.1875f, 0.1249f)).setParent(_parts + 4);
	_parts[6] = Cube(Vec3(0.5, 1, 0),	Vec3(),	Vec3(0.5, -0.5, 0.f),	Vec3(0.1249f, 0.1875f, 0.1249f)).setParent(_parts);
	_parts[7] = Cube(Vec3(0.5, -1, 0),	Vec3(),	Vec3(0, -0.5, 0),		Vec3(0.1249f, 0.1875f, 0.1249f)).setParent(_parts + 6);
	_parts[8] = Cube(Vec3(0.25, 0, 0),	Vec3(),	Vec3(0, -0.5, 0.f),		Vec3(0.1249f, 0.1875f, 0.1249f)).setParent(_parts);
	_parts[9] = Cube(Vec3(0, -1, 0),	Vec3(),	Vec3(0, -0.5, 0),		Vec3(0.1249f, 0.1875f, 0.1249f)).setParent(_parts + 8);
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

}

void		Human::render(Shaders &shader)
{
	for (size_t i = 0; i < 10; i++)
		_parts[i].render(shader, _colors[i]);
}

void 		Human::update(float delta)
{

}

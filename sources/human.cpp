#include "human.hpp"
using namespace mmatrix;

Human::Human(void)
{
	_body = Cube(Vec3(0, 0.375f, 0),		Vec3(),	Vec3(0.0f, 0.5f, 0.0f),	Vec3(0.25f, 0.375f, 0.125f));
	_head = Cube(Vec3(0, 1, 0),				Vec3(), Vec3(0.0f, 0.5f, 0.0f),	Vec3(0.25f));
	_leftArmUp = Cube(Vec3(-0.5, 1, 0),		Vec3(),	Vec3(-0.5, -0.5, 0.f),	Vec3(0.1249f, 0.1875f, 0.1249f));
	_leftArmDown = Cube(Vec3(-0.5, -1, 0),	Vec3(),	Vec3(0, -0.5, 0), 		Vec3(0.1249f, 0.1875f, 0.1249f));
	_leftLegUp = Cube(Vec3(-0.25, 0, 0),	Vec3(),	Vec3(0, -0.5, 0.f),		Vec3(0.1249f, 0.1875f, 0.1249f));
	_leftLegDown = Cube(Vec3(0, -1, 0),		Vec3(),	Vec3(0, -0.5, 0),		Vec3(0.1249f, 0.1875f, 0.1249f));
	_rightArmUp = Cube(Vec3(0.5, 1, 0),		Vec3(),	Vec3(0.5, -0.5, 0.f),	Vec3(0.1249f, 0.1875f, 0.1249f));
	_rightArmDown = Cube(Vec3(0.5, -1, 0),	Vec3(),	Vec3(0, -0.5, 0),		Vec3(0.1249f, 0.1875f, 0.1249f));
	_rightLegUp = Cube(Vec3(0.25, 0, 0),	Vec3(),	Vec3(0, -0.5, 0.f),		Vec3(0.1249f, 0.1875f, 0.1249f));
	_rightLegDown = Cube(Vec3(0, -1, 0),	Vec3(),	Vec3(0, -0.5, 0),		Vec3(0.1249f, 0.1875f, 0.1249f));
	_head.setParent(&_body);
	_leftArmUp.setParent(&_body);
	_leftArmDown.setParent(&_leftArmUp);
	_leftLegUp.setParent(&_body);
	_leftLegDown.setParent(&_leftLegUp);
	_rightArmUp.setParent(&_body);
	_rightArmDown.setParent(&_rightArmUp);
	_rightLegUp.setParent(&_body);
	_rightLegDown.setParent(&_rightLegUp);
	
}

void		Human::render(Shaders &shader)
{
	_body.render(shader, Vec3(0.5f, 0.f, 0.f));
	_head.render(shader, Vec3(0.9960784314f, 0.7647058824f, 0.6745098039f));
	_leftArmUp.render(shader, Vec3(0.5f, 0.f, 0.f));
	_leftArmDown.render(shader, Vec3(0.9960784314f, 0.7647058824f, 0.6745098039f));
	_leftLegUp.render(shader, Vec3(0.f, 0.f, 0.5f));
	_leftLegDown.render(shader, Vec3(0.9960784314f, 0.7647058824f, 0.6745098039f));
	_rightArmUp.render(shader, Vec3(0.5f, 0.f, 0.f));
	_rightArmDown.render(shader, Vec3(0.9960784314f, 0.7647058824f, 0.6745098039f));
	_rightLegUp.render(shader, Vec3(0.f, 0.f, 0.5f));
	_rightLegDown.render(shader, Vec3(0.9960784314f, 0.7647058824f, 0.6745098039f));
}

void 		Human::update(float delta)
{

}

#include "cube.hpp"
#include "mmatrix.hpp"

#include "debug.hpp"

using namespace mmatrix;

Mesh		*Cube::mesh = nullptr;

void		Cube::Load(void)
{
	static const GLfloat g_vertex_buffer_data[] = {
		-0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f, -0.5f, -0.5f, -0.5f,
		0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, 0.5f, 0.5f, -0.5f,
		-0.5f, 0.5f, 0.5f, -0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.5f,
		0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.5f, -0.5f, -0.5f, 0.5f,
		-0.5f, 0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, 0.5f, 0.5f,
		-0.5f, -0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f, -0.5f, -0.5f,
		0.5f, 0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.5f, -0.5f, -0.5f,
		0.5f, -0.5f, 0.5f, 0.5f, -0.5f, -0.5f, 0.5f, 0.5f, 0.5f,
		-0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, -0.5f, 0.5f, -0.5f,
		0.5f, 0.5f, -0.5f, -0.5f, 0.5f, -0.5f, 0.5f, 0.5f, 0.5f,
		-0.5f, -0.5f, 0.5f, -0.5f, -0.5f, -0.5f, 0.5f, -0.5f, 0.5f,
		0.5f, -0.5f, -0.5f, 0.5f, -0.5f, 0.5f, -0.5f, -0.5f, -0.5f
	};
	static const GLfloat g_color_buffer_data[] = {
		0, 0, 1, 0, 0, 1, 0, 0, 1,
		0, 1, 0, 0, 1, 0, 0, 1, 0,
		0, 1, 1, 0, 1, 1, 0, 1, 1,
		1, 0, 0, 1, 0, 0, 1, 0, 0,
		1, 0, 1, 1, 0, 1, 1, 0, 1,
		1, 1, 0, 1, 1, 0, 1, 1, 0,
		1, 1, 1, 1, 1, 1, 1, 1, 1,
		0, 0, 1, 0, 0, 1, 0, 0, 1,
		0, 1, 0, 0, 1, 0, 0, 1, 0,
		0, 1, 1, 0, 1, 1, 0, 1, 1,
		1, 0, 0, 1, 0, 0, 1, 0, 0,
		1, 0, 1, 1, 0, 1, 1, 0, 1
	};
	mesh = new Mesh(2);
	mesh->begin();
	mesh->add(0, GL_FLOAT, 3, (void *)g_vertex_buffer_data, 36);
	mesh->add(1, GL_FLOAT, 3, (void *)g_color_buffer_data, 36);
	mesh->end();
}

void		Cube::Render(void)
{
	mesh->render(GL_TRIANGLES);
}

void		Cube::Unload(void)
{
	delete mesh;
}

/* ******************** */
/* * CLASS MEMBER     * */
/* ******************** */
using namespace mmatrix;

Cube::Cube(const Vec3 &pos, const Vec3 &rot, const Vec3 &offset, const Vec3 &scale) :
	_position(pos), _rotate(rot), _offset(offset), _scale(scale), _parent(nullptr)
{}

Cube	&Cube::setParent(Cube *parent)
{
	_parent = parent;
	return (*this);
}

Mat4x4	Cube::toMatrix(const bool isChild)
{
	Mat4x4	parentMatrix;
	Mat4x4	matrix;

	if (_parent != nullptr)
	{
		parentMatrix = _parent->toMatrix(true);
		matrix = Mat4x4::Translate(_position * _parent->_scale);
	}
	else
	{
		parentMatrix = Mat4x4::Identity();
		matrix = Mat4x4::Translate(_position);
	}
	matrix.rotate(Vec3(0, 0, 1), _rotate[2]);
	matrix.rotate(Vec3(0, 1, 0), _rotate[1]);
	matrix.rotate(Vec3(1, 0, 0), _rotate[0]);
	if (!isChild)
	{
		matrix.scale_aniso(_scale);
		matrix.translate_in_place(_offset);
	}
	return (parentMatrix * matrix);
}

Cube	&Cube::setRotate(const Vec3 &rot)
{
	_rotate = rot;
	return (*this);
}

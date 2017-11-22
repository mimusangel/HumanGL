#ifndef CUBE_HPP
# define CUBE_HPP

# include "humangl.hpp"
# include "mesh.hpp"
# include "shaders.hpp"
using namespace mmatrix;

class Cube {
private:
	static Mesh		*mesh;

public:
	static void 	Load(void);
	static void		Unload(void);
	static void		Render(void);

private:
	Vec3	_position;
	Vec3	_rotate;
	Vec3	_offset;
	Vec3	_scale;
	Cube	*_parent;

public:
	bool	visible;
	Cube(const Vec3 &pos = Vec3(), const Vec3 &rot = Vec3(), const Vec3 &offset = Vec3(), const Vec3 &scale = Vec3(1.f));
	Cube	&setParent(Cube *parent);
	Mat4x4	toMatrix(const bool isChild = false);
	Cube	&setRotate(const Vec3 &rot);
	void	render(Shaders &shader, const Vec3 &color = Vec3(1.f));
	Vec3	&getRot(void);
	Vec3	&getPos(void);
	Vec3	&getScale(void);
	Cube	&translate(const Vec3 &pos);
};

#endif

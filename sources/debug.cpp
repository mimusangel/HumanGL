#include <iostream>
using namespace std;
#include "debug.hpp"
using namespace mmatrix;

void			Debug::print(Vec2 &value)
{
	const float	*v = (float*)&value;
	printf("Vec2: %.2f, %.2f\n", v[0], v[1]);
}

void			Debug::print(Vec3 &value)
{
	const float	*v = (float*)&value;
	printf("Vec3: %.2f, %.2f, %.2f\n", v[0], v[1], v[2]);
}

void			Debug::print(Vec4 &value)
{
	const float	*v = (float*)&value;
	printf("Vec4: %.2f, %.2f, %.2f, %.2f\n", v[0], v[1], v[2], v[3]);
}

void			Debug::print(Mat4x4 &value)
{
	const float	*v = (float*)&value;
	printf("Mat4:\n%.2f, %.2f, %.2f, %.2f\n%.2f, %.2f, %.2f, %.2f\n%.2f, %.2f, %.2f, %.2f\n%.2f, %.2f, %.2f, %.2f\n",
		v[0], v[1], v[2], v[3],
		v[4], v[5], v[6], v[7],
		v[8], v[9], v[10], v[11],
		v[12], v[13], v[14], v[15]
	);
}

void			Debug::print(Quat &value)
{
	const float	*v = (float*)&value;
	printf("Quat: %.2f, %.2f, %.2f, %.2f\n", v[0], v[1], v[2], v[3]);
}

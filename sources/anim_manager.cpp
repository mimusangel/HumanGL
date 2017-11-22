#include <cmath>
#include "anim.hpp"

Anim	AnimManager::loadIdle()
{
	Anim anim(10);
	anim.addAnimPoint(-1, 1, Vec3(0.f, -0.01f, 0.0f))
		.addAnimPoint(-1, 2, Vec3(0.f, 0.0f, 0.0f))
		.addAnimPoint(1, 1, Vec3(0.1f, 0.f, 0.f))
		.addAnimPoint(1, 2, Vec3(0.f, 0.f, 0.f))
		.addAnimPoint(2, 1, Vec3(0.f, 0.f, -0.1f))
		.addAnimPoint(2, 2, Vec3(0.f, 0.f, 0.0f))
		.addAnimPoint(3, 1, Vec3(0.f, 0.f, 0.1f))
		.addAnimPoint(3, 2, Vec3(0.f, 0.f, 0.0f))
		.addAnimPoint(4, 1, Vec3(-0.1f, -0.1f, 0.0f))
		.addAnimPoint(4, 2, Vec3(0.f, 0.f, 0.0f))
		.addAnimPoint(5, 1, Vec3(0.1f, 0.0f, 0.0f))
		.addAnimPoint(5, 2, Vec3(0.f, 0.0f, 0.0f))
		.addAnimPoint(6, 1, Vec3(0.f, 0.f, 0.1f))
		.addAnimPoint(6, 2, Vec3(0.f, 0.f, 0.0f))
		.addAnimPoint(7, 1, Vec3(0.f, 0.f, -0.1f))
		.addAnimPoint(7, 2, Vec3(0.f, 0.f, 0.0f))
		.addAnimPoint(8, 1, Vec3(-0.1f, 0.1f, 0.0f))
		.addAnimPoint(8, 2, Vec3(0.f, 0.f, 0.0f))
		.addAnimPoint(9, 1, Vec3(0.1f, 0.0f, 0.0f))
		.addAnimPoint(9, 2, Vec3(0.f, 0.0f, 0.0f))
	;
	return (anim);
}

Anim	AnimManager::loadWalk()
{
	return (Anim(10));
}

Anim	AnimManager::loadRun()
{
	return (Anim(10));
}

Anim	AnimManager::loadJump()
{
	return (Anim(10));
}

Anim	AnimManager::loadTwerk()
{
	return (Anim(10));
}

Anim	AnimManager::loadCrouch()
{
	return (Anim(10));
}

Anim	AnimManager::loadMasturbate()
{
	Anim anim(10);
	anim.addAnimPoint(0, 0.1f * 0.001f, Vec3(TORADIANS(-75.f), 0.f, 0.0f))
		.addAnimPoint(0, 0.1f * 16.f, Vec3(TORADIANS(-75.f), 0.f, 0.0f))
		.addAnimPoint(1, 0.1f * 0.001f, Vec3(TORADIANS(25.f), 0.f, 0.0f))
		.addAnimPoint(1, 0.1f * 15.f, Vec3(TORADIANS(25.f), 0.f, 0.0f))
		.addAnimPoint(1, 0.1f * 16.f, Vec3(TORADIANS(-5.f), 0.f, 0.0f))
		.addAnimPoint(2, 0.1f * 2.f, Vec3(TORADIANS(-25.f), 0.f, TORADIANS(10.f)))
		.addAnimPoint(2, 0.1f * 4.f, Vec3(TORADIANS(-25.f), 0.f, TORADIANS(10.f)))
		.addAnimPoint(2, 0.1f * 6.f, Vec3(TORADIANS(-15.f), 0.f, TORADIANS(10.f)))
		.addAnimPoint(2, 0.1f * 8.f, Vec3(TORADIANS(-25.f), 0.f, TORADIANS(10.f)))
		.addAnimPoint(2, 0.1f * 10.f, Vec3(TORADIANS(-15.f), 0.f, TORADIANS(10.f)))
		.addAnimPoint(2, 0.1f * 12.f, Vec3(TORADIANS(-25.f), 0.f, TORADIANS(10.f)))
		.addAnimPoint(2, 0.1f * 14.f, Vec3(TORADIANS(-15.f), 0.f, TORADIANS(10.f)))
		.addAnimPoint(2, 0.1f * 16.f, Vec3(TORADIANS(-25.f), 0.f, TORADIANS(10.f)))
		.addAnimPoint(3, 0.1f * 2.f, Vec3(0.f, 0.f, 0.f))
		.addAnimPoint(3, 0.1f * 4.f, Vec3(TORADIANS(-10.f), 0.f, TORADIANS(25.f)))
		.addAnimPoint(3, 0.1f * 16.f, Vec3(TORADIANS(-10.f), 0.f, TORADIANS(25.f)))
		.addAnimPoint(4, 0.1f * 4.f, Vec3(TORADIANS(-10.f), 0.f, TORADIANS(-15.f)))
		.addAnimPoint(4, 0.1f * 16.f, Vec3(TORADIANS(-10.f), 0.f, TORADIANS(-15.f)))
		.addAnimPoint(5, 0.1f * 4.f, Vec3(TORADIANS(10.f), 0.f, 0.f))
		.addAnimPoint(5, 0.1f * 16.f, Vec3(TORADIANS(10.f), 0.f, 0.f))
		.addAnimPoint(6, 0.1f * 4.f, Vec3(TORADIANS(10.f), 0.f, 0.f))
		.addAnimPoint(6, 0.1f * 16.f, Vec3(TORADIANS(10.f), 0.f, 0.f))
		.addAnimPoint(7, 0.1f * 4.f, Vec3(TORADIANS(-10.f), 0.f, 0.f))
		.addAnimPoint(7, 0.1f * 16.f, Vec3(TORADIANS(-10.f), 0.f, 0.f))
		.addAnimPoint(8, 0.1f * 4.f, Vec3(TORADIANS(-10.f), 0.f, TORADIANS(10.f)))
		.addAnimPoint(8, 0.1f * 16.f, Vec3(TORADIANS(-10.f), 0.f, TORADIANS(10.f)))
		.addAnimPoint(9, 0.1f * 4.f, Vec3(TORADIANS(5.f), 0.f, TORADIANS(5.f)))
		.addAnimPoint(9, 0.1f * 16.f, Vec3(TORADIANS(5.f), 0.f, TORADIANS(5.f)))
	;
	return (anim);
}

Anim AnimManager::loadExorciste()
{
	return (Anim(10));
}

Anim AnimManager::loadNeo()
{
	return (Anim(10));
}

Anim AnimManager::loadCloClo()
{
	return (Anim(10));
}

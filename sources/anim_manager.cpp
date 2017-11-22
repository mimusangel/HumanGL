#include <cmath>
#include "anim.hpp"

Anim	AnimManager::loadIdle(float speed)
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

Anim	AnimManager::loadWalk(float speed)
{
	Anim	anim(10);

	anim.setLoop(true)
		.addAnimPoint(2, speed * 0.5, Vec3(TORADIANS(60), 0, 0))
		.addAnimPoint(2, speed * 1.5, Vec3(TORADIANS(-60), 0, 0))
		.addAnimPoint(2, speed * 2, Vec3(0, 0, 0))
		.addAnimPoint(6, speed * 0.5, Vec3(TORADIANS(-60), 0, 0))
		.addAnimPoint(6, speed * 1.5, Vec3(TORADIANS(60), 0, 0))
		.addAnimPoint(6, speed * 2, Vec3(0, 0, 0))
		.addAnimPoint(4, speed * 0.5, Vec3(TORADIANS(-60), 0, 0))
		.addAnimPoint(4, speed * 1, Vec3(0, 0, 0))
		.addAnimPoint(4, speed * 2, Vec3(0, 0, 0))
		.addAnimPoint(5, speed * 0.5, Vec3(TORADIANS(60), 0, 0))
		.addAnimPoint(5, speed * 1, Vec3(0, 0, 0))
		.addAnimPoint(5, speed * 2, Vec3(0, 0, 0))
		.addAnimPoint(8, speed * 1, Vec3(0, 0, 0))
		.addAnimPoint(8, speed * 1.5, Vec3(TORADIANS(-60), 0, 0))
		.addAnimPoint(8, speed * 2, Vec3(0, 0, 0))
		.addAnimPoint(9, speed * 1, Vec3(0, 0, 0))
		.addAnimPoint(9, speed * 1.5, Vec3(TORADIANS(60), 0, 0))
		.addAnimPoint(9, speed * 2, Vec3(0, 0, 0));
	return (anim);
}

Anim	AnimManager::loadRun(float speed)
{
	Anim	anim(10);
	anim.setLoop(true);
	//bras
	anim.addAnimPoint(2, speed * 0.5, Vec3(TORADIANS(60), 0, 0))
		.addAnimPoint(2, speed * 1.5, Vec3(TORADIANS(-80), 0, 0))
		.addAnimPoint(2, speed * 2, Vec3(0, 0, 0))
		.addAnimPoint(3, speed * 0.5, Vec3(TORADIANS(-30), 0, 0))
		.addAnimPoint(3, speed * 1.0, Vec3(0, 0, 0))
		.addAnimPoint(3, speed * 1.5, Vec3(TORADIANS(-60), 0, 0))
		.addAnimPoint(3, speed * 2.0, Vec3(0, 0, 0))
		.addAnimPoint(6, speed * 0.5, Vec3(TORADIANS(-80), 0, 0))
		.addAnimPoint(6, speed * 1.5, Vec3(TORADIANS(60), 0, 0))
		.addAnimPoint(6, speed * 2, Vec3(0, 0, 0))
		.addAnimPoint(7, speed * 0.5, Vec3(TORADIANS(-60), 0, 0))
		.addAnimPoint(7, speed * 1.0, Vec3(0, 0, 0))
		.addAnimPoint(7, speed * 1.5, Vec3(TORADIANS(-30), 0, 0))
		.addAnimPoint(7, speed * 2.0, Vec3(0, 0, 0))
	//jambe
		.addAnimPoint(4, speed * 0.5, Vec3(TORADIANS(-80), 0, 0))
		.addAnimPoint(4, speed * 1, Vec3(0, 0, 0))
		.addAnimPoint(4, speed * 1.5, Vec3(TORADIANS(30), 0, 0))
		.addAnimPoint(4, speed * 2, Vec3(0, 0, 0))

		.addAnimPoint(5, speed * 0.5, Vec3(TORADIANS(60), 0, 0))
		.addAnimPoint(5, speed * 1, Vec3(0, 0, 0))
		.addAnimPoint(5, speed * 1.5, Vec3(TORADIANS(60), 0, 0))
		.addAnimPoint(5, speed * 2, Vec3(0, 0, 0))

		.addAnimPoint(8, speed * 0.5, Vec3(TORADIANS(60), 0, 0))
		.addAnimPoint(8, speed * 1, Vec3(0, 0, 0))
		.addAnimPoint(8, speed * 1.5, Vec3(TORADIANS(-80), 0, 0))
		.addAnimPoint(8, speed * 2, Vec3(0, 0, 0))

		.addAnimPoint(9, speed * 0.5, Vec3(TORADIANS(60), 0, 0))
		.addAnimPoint(9, speed * 1, Vec3(0, 0, 0))
		.addAnimPoint(9, speed * 1.5, Vec3(TORADIANS(60), 0, 0))
		.addAnimPoint(9, speed * 2, Vec3(0, 0, 0))
	;
	return (anim);
}

Anim	AnimManager::loadJump(float speed)
{
	Anim	anim(10);
	anim.addAnimPoint(-1, speed * 1.f, Vec3(0.f, -0.1f, 0.0f))
		.addAnimPoint(-1, speed * 4.f, Vec3(0.f, 0.5f, 0.f))
		.addAnimPoint(-1, speed * 6.f, Vec3(0.f, 0.f, 0.f))
		.addAnimPoint(0, speed * 1.f, Vec3(TORADIANS(5.f), 0.f, 0.0f))
		.addAnimPoint(0, speed * 4.f, Vec3(TORADIANS(10.f), 0.f, 0.0f))
		.addAnimPoint(0, speed * 6.f, Vec3(0.f, 0.f, 0.0f))
		.addAnimPoint(2, speed * 1.f, Vec3(TORADIANS(-15.f), TORADIANS(-20.f), 0.0f))
		.addAnimPoint(2, speed * 4.f, Vec3(TORADIANS(-150.f), 0.f, 0.0f))
		.addAnimPoint(2, speed * 6.f, Vec3(0.f, 0.f, 0.0f))
		.addAnimPoint(3, speed * 1.f, Vec3(TORADIANS(-15.f), 0.f, 0.0f))
		.addAnimPoint(3, speed * 4.f, Vec3(TORADIANS(-5.f), 0.f, 0.0f))
		.addAnimPoint(3, speed * 6.f, Vec3(0.f, 0.f, 0.0f))
		.addAnimPoint(4, speed * 1.f, Vec3(TORADIANS(-15.f), TORADIANS(-15.f), 0.0f))
		.addAnimPoint(4, speed * 4.f, Vec3(TORADIANS(5.f), TORADIANS(-15.f), 0.0f))
		.addAnimPoint(4, speed * 6.f, Vec3(0.f, 0.f, 0.0f))
		.addAnimPoint(5, speed * 1.f, Vec3(TORADIANS(12.f), 0.f, 0.0f))
		.addAnimPoint(5, speed * 4.f, Vec3(TORADIANS(20.f), 0.f, 0.0f))
		.addAnimPoint(5, speed * 6.f, Vec3(0.f, 0.f, 0.0f))
		.addAnimPoint(6, speed * 1.f, Vec3(TORADIANS(-15.f), TORADIANS(20.f), 0.0f))
		.addAnimPoint(6, speed * 4.f, Vec3(TORADIANS(-150.f), 0.f, 0.0f))
		.addAnimPoint(6, speed * 6.f, Vec3(0.f, 0.f, 0.0f))
		.addAnimPoint(7, speed * 1.f, Vec3(TORADIANS(-15.f), 0.f, 0.0f))
		.addAnimPoint(7, speed * 4.f, Vec3(TORADIANS(-5.f), 0.f, 0.0f))
		.addAnimPoint(7, speed * 6.f, Vec3(0.f, 0.f, 0.0f))
		.addAnimPoint(8, speed * 1.f, Vec3(TORADIANS(-15.f), TORADIANS(15.f), 0.0f))
		.addAnimPoint(8, speed * 4.f, Vec3(TORADIANS(5.f), TORADIANS(-15.f), 0.0f))
		.addAnimPoint(8, speed * 6.f, Vec3(0.f, 0.f, 0.0f))
		.addAnimPoint(9, speed * 1.f, Vec3(TORADIANS(12.f), 0.f, 0.0f))
		.addAnimPoint(9, speed * 4.f, Vec3(TORADIANS(20.f), 0.f, 0.0f))
		.addAnimPoint(9, speed * 6.f, Vec3(0.f, 0.f, 0.0f))
	;
	return (anim);
}

Anim	AnimManager::loadTwerk(float speed)
{
	Anim	anim(10);

	return (anim);
}

Anim	AnimManager::loadCrouch(float speed)
{
	Anim	anim(10);
	anim.addAnimPoint(-1, speed * 2.f, Vec3(0.f, -0.08f, 0.0f))
		.addAnimPoint(-1, speed * 4.f, Vec3(0.f, 0.f, 0.0f))
		.addAnimPoint(0, speed * 2.f, Vec3(TORADIANS(15.f), 0.f, 0.0f))
		.addAnimPoint(0, speed * 4.f, Vec3(0.f, 0.f, 0.0f))
		.addAnimPoint(1, speed * 2.f, Vec3(TORADIANS(-20.f), 0.f, 0.0f))
		.addAnimPoint(1, speed * 4.f, Vec3(0.f, 0.f, 0.0f))
		.addAnimPoint(2, speed * 2.f, Vec3(TORADIANS(20.f), 0.f, 0.0f))
		.addAnimPoint(2, speed * 4.f, Vec3(0.f, 0.f, 0.0f))
		.addAnimPoint(3, speed * 2.f, Vec3(TORADIANS(-50.f), 0.f, 0.0f))
		.addAnimPoint(3, speed * 4.f, Vec3(0.f, 0.f, 0.0f))
		.addAnimPoint(4, speed * 2.f, Vec3(TORADIANS(-80.f), 0.f, 0.0f))
		.addAnimPoint(4, speed * 4.f, Vec3(0.f, 0.f, 0.0f))
		.addAnimPoint(5, speed * 2.f, Vec3(TORADIANS(80.f), 0.f, 0.0f))
		.addAnimPoint(5, speed * 4.f, Vec3(0.f, 0.f, 0.0f))
		.addAnimPoint(6, speed * 2.f, Vec3(TORADIANS(-10.f), 0.f, 0.0f))
		.addAnimPoint(6, speed * 4.f, Vec3(0.f, 0.f, 0.0f))
		.addAnimPoint(7, speed * 2.f, Vec3(TORADIANS(-40.f), 0.f, 0.0f))
		.addAnimPoint(7, speed * 4.f, Vec3(0.f, 0.f, 0.0f))
		.addAnimPoint(8, speed * 2.f, Vec3(TORADIANS(-50.f), 0.f, 0.0f))
		.addAnimPoint(8, speed * 4.f, Vec3(0.f, 0.f, 0.0f))
		.addAnimPoint(9, speed * 2.f, Vec3(TORADIANS(100.f), 0.f, 0.0f))
		.addAnimPoint(9, speed * 4.f, Vec3(0.f, 0.f, 0.0f))
	;
	return (anim);
}

Anim	AnimManager::loadMasturbate(float speed)
{
	Anim anim(10);
	anim.addAnimPoint(0, speed * 0.001f, Vec3(TORADIANS(-75.f), 0.f, 0.0f))
		.addAnimPoint(0, speed * 16.f, Vec3(TORADIANS(-75.f), 0.f, 0.0f))
		.addAnimPoint(1, speed * 0.001f, Vec3(TORADIANS(25.f), 0.f, 0.0f))
		.addAnimPoint(1, speed * 15.f, Vec3(TORADIANS(25.f), 0.f, 0.0f))
		.addAnimPoint(1, speed * 16.f, Vec3(TORADIANS(-5.f), 0.f, 0.0f))
		.addAnimPoint(2, speed * 2.f, Vec3(TORADIANS(-25.f), 0.f, TORADIANS(10.f)))
		.addAnimPoint(2, speed * 4.f, Vec3(TORADIANS(-25.f), 0.f, TORADIANS(10.f)))
		.addAnimPoint(2, speed * 6.f, Vec3(TORADIANS(-15.f), 0.f, TORADIANS(10.f)))
		.addAnimPoint(2, speed * 8.f, Vec3(TORADIANS(-25.f), 0.f, TORADIANS(10.f)))
		.addAnimPoint(2, speed * 10.f, Vec3(TORADIANS(-15.f), 0.f, TORADIANS(10.f)))
		.addAnimPoint(2, speed * 12.f, Vec3(TORADIANS(-25.f), 0.f, TORADIANS(10.f)))
		.addAnimPoint(2, speed * 14.f, Vec3(TORADIANS(-15.f), 0.f, TORADIANS(10.f)))
		.addAnimPoint(2, speed * 16.f, Vec3(TORADIANS(-25.f), 0.f, TORADIANS(10.f)))
		.addAnimPoint(3, speed * 2.f, Vec3(0.f, 0.f, 0.f))
		.addAnimPoint(3, speed * 4.f, Vec3(TORADIANS(-10.f), 0.f, TORADIANS(25.f)))
		.addAnimPoint(3, speed * 16.f, Vec3(TORADIANS(-10.f), 0.f, TORADIANS(25.f)))
		.addAnimPoint(4, speed * 4.f, Vec3(TORADIANS(-10.f), 0.f, TORADIANS(-15.f)))
		.addAnimPoint(4, speed * 16.f, Vec3(TORADIANS(-10.f), 0.f, TORADIANS(-15.f)))
		.addAnimPoint(5, speed * 4.f, Vec3(TORADIANS(10.f), 0.f, 0.f))
		.addAnimPoint(5, speed * 16.f, Vec3(TORADIANS(10.f), 0.f, 0.f))
		.addAnimPoint(6, speed * 4.f, Vec3(TORADIANS(10.f), 0.f, 0.f))
		.addAnimPoint(6, speed * 16.f, Vec3(TORADIANS(10.f), 0.f, 0.f))
		.addAnimPoint(7, speed * 4.f, Vec3(TORADIANS(-10.f), 0.f, 0.f))
		.addAnimPoint(7, speed * 16.f, Vec3(TORADIANS(-10.f), 0.f, 0.f))
		.addAnimPoint(8, speed * 4.f, Vec3(TORADIANS(-10.f), 0.f, TORADIANS(10.f)))
		.addAnimPoint(8, speed * 16.f, Vec3(TORADIANS(-10.f), 0.f, TORADIANS(10.f)))
		.addAnimPoint(9, speed * 4.f, Vec3(TORADIANS(5.f), 0.f, TORADIANS(5.f)))
		.addAnimPoint(9, speed * 16.f, Vec3(TORADIANS(5.f), 0.f, TORADIANS(5.f)))
	;
	return (anim);
}

Anim AnimManager::loadExorciste(float speed)
{
	Anim	anim(10);

	return (anim);
}

Anim AnimManager::loadNeo(float speed)
{
	Anim	anim(10);

	anim.addAnimPoint(-1, 0.5, Vec3(0, -0.1, -0.25))
		.addAnimPoint(-1, 4.5, Vec3(0, -0.1, -0.25))
		.addAnimPoint(-1, 5, Vec3(0, 0, 0))
		.addAnimPoint(0, 0.5, Vec3(TORADIANS(-90), 0, 0))
		.addAnimPoint(0, 4.5, Vec3(TORADIANS(-90), 0, 0))
		.addAnimPoint(0, 5, Vec3(0, 0, 0))
		.addAnimPoint(2, 0.25, Vec3(TORADIANS(-90), TORADIANS(-90), TORADIANS(0)))
		.addAnimPoint(2, 0.4, Vec3(TORADIANS(-160), TORADIANS(-45), TORADIANS(0)))
		.addAnimPoint(2, 4.5, Vec3(TORADIANS(-16000000), TORADIANS(0), TORADIANS(0)))
		.addAnimPoint(6, 0.25, Vec3(TORADIANS(-90), TORADIANS(90), TORADIANS(0)))
		.addAnimPoint(6, 0.4, Vec3(TORADIANS(-160), TORADIANS(45), TORADIANS(0)))
		.addAnimPoint(6, 4.5, Vec3(TORADIANS(16000000), TORADIANS(0), TORADIANS(0)))
		.addAnimPoint(4, 0.5, Vec3(TORADIANS(45), TORADIANS(10), TORADIANS(-10)))
		.addAnimPoint(4, 4.5, Vec3(TORADIANS(45), TORADIANS(10), TORADIANS(-10)))
		.addAnimPoint(4, 5, Vec3(0, 0, 0))
		.addAnimPoint(8, 0.5, Vec3(TORADIANS(45), TORADIANS(-10), TORADIANS(10)))
		.addAnimPoint(8, 4.5, Vec3(TORADIANS(45), TORADIANS(-10), TORADIANS(10)))
		.addAnimPoint(8, 5, Vec3(0, 0, 0))
		.addAnimPoint(5, 0.5, Vec3(TORADIANS(45), TORADIANS(10), 0))
		.addAnimPoint(5, 4.5, Vec3(TORADIANS(45), TORADIANS(10), 0))
		.addAnimPoint(5, 5, Vec3(0, 0, 0))
		.addAnimPoint(9, 0.5, Vec3(TORADIANS(45), TORADIANS(-10), 0))
		.addAnimPoint(9, 4.5, Vec3(TORADIANS(45), TORADIANS(-10), 0))
		.addAnimPoint(9, 5, Vec3(0, 0, 0));

	return (anim);
}

Anim AnimManager::loadCloClo(float speed)
{
	Anim	anim(10);
	anim.addAnimPoint(0, speed * 6.f, Vec3(0.f, 0.f, 0.f))
		.addAnimPoint(0, speed * 10.f, Vec3(0.f, TORADIANS(360.f), 0.f))
		// Bras Gauche
		.addAnimPoint(2, speed * 1.f, Vec3(TORADIANS(-45.f), 0.f, 0.f))
		.addAnimPoint(2, speed * 1.5f, Vec3(TORADIANS(-35.f), 0.f, 0.f))
		.addAnimPoint(2, speed * 2.f, Vec3(TORADIANS(-80.f), 0.f, 0.f))
		.addAnimPoint(2, speed * 3.f, Vec3(TORADIANS(-5.f), 0.f, 0.f))
		.addAnimPoint(2, speed * 4.f, Vec3(TORADIANS(-45.f), 0.f, 0.f))
		.addAnimPoint(2, speed * 4.5f, Vec3(TORADIANS(-35.f), 0.f, 0.f))
		.addAnimPoint(2, speed * 5.f, Vec3(TORADIANS(-80.f), 0.f, 0.f))
		.addAnimPoint(2, speed * 6.f, Vec3(0.f, 0.f, 0.f))
		.addAnimPoint(2, speed * 7.5f, Vec3(0.f, TORADIANS(-30.f), TORADIANS(-85.f)))
		.addAnimPoint(2, speed * 10.f, Vec3(0.f, 0.f, 0.f))
		.addAnimPoint(3, speed * 1.f, Vec3(TORADIANS(-135.f), 0.f, 0.f))
		.addAnimPoint(3, speed * 1.5f, Vec3(TORADIANS(-145.f), 0.f, 0.f))
		.addAnimPoint(3, speed * 2.f, Vec3(TORADIANS(-15.f), 0.f, 0.f))
		.addAnimPoint(3, speed * 2.5f, Vec3(TORADIANS(-45.f), 0.f, 0.f))
		.addAnimPoint(3, speed * 3.f, Vec3(TORADIANS(-5.f), 0.f, 0.f))
		.addAnimPoint(3, speed * 4.f, Vec3(TORADIANS(-135.f), 0.f, 0.f))
		.addAnimPoint(3, speed * 4.5f, Vec3(TORADIANS(-145.f), 0.f, 0.f))
		.addAnimPoint(3, speed * 5.f, Vec3(TORADIANS(-15.f), 0.f, 0.f))
		.addAnimPoint(3, speed * 5.5f, Vec3(TORADIANS(-45.f), 0.f, 0.f))
		.addAnimPoint(3, speed * 6.f, Vec3(0.f, 0.f, 0.f))
		.addAnimPoint(3, speed * 7.5f, Vec3(TORADIANS(-45.f), 0.f, 0.f))
		.addAnimPoint(3, speed * 10.f, Vec3(0.f, 0.f, 0.f))
		// Bras droite
		.addAnimPoint(6, speed * 1.f, Vec3(TORADIANS(-45.f), 0.f, 0.f))
		.addAnimPoint(6, speed * 1.5f, Vec3(TORADIANS(-35.f), 0.f, 0.f))
		.addAnimPoint(6, speed * 2.f, Vec3(TORADIANS(-80.f), 0.f, 0.f))
		.addAnimPoint(6, speed * 3.f, Vec3(TORADIANS(-5.f), 0.f, 0.f))
		.addAnimPoint(6, speed * 4.f, Vec3(TORADIANS(-45.f), 0.f, 0.f))
		.addAnimPoint(6, speed * 4.5f, Vec3(TORADIANS(-35.f), 0.f, 0.f))
		.addAnimPoint(6, speed * 5.f, Vec3(TORADIANS(-80.f), 0.f, 0.f))
		.addAnimPoint(6, speed * 6.f, Vec3(0.f, 0.f, 0.f))
		.addAnimPoint(6, speed * 7.5f, Vec3(0.f, TORADIANS(-30.f), TORADIANS(85.f)))
		.addAnimPoint(6, speed * 10.f, Vec3(0.f, 0.f, 0.f))
		.addAnimPoint(7, speed * 1.f, Vec3(TORADIANS(-135.f), 0.f, 0.f))
		.addAnimPoint(7, speed * 1.5f, Vec3(TORADIANS(-145.f), 0.f, 0.f))
		.addAnimPoint(7, speed * 2.f, Vec3(TORADIANS(-15.f), 0.f, 0.f))
		.addAnimPoint(7, speed * 2.5f, Vec3(TORADIANS(-45.f), 0.f, 0.f))
		.addAnimPoint(7, speed * 3.f, Vec3(TORADIANS(-5.f), 0.f, 0.f))
		.addAnimPoint(7, speed * 4.f, Vec3(TORADIANS(-135.f), 0.f, 0.f))
		.addAnimPoint(7, speed * 4.5f, Vec3(TORADIANS(-145.f), 0.f, 0.f))
		.addAnimPoint(7, speed * 5.f, Vec3(TORADIANS(-15.f), 0.f, 0.f))
		.addAnimPoint(7, speed * 5.5f, Vec3(TORADIANS(-45.f), 0.f, 0.f))
		.addAnimPoint(7, speed * 6.f, Vec3(0.f, 0.f, 0.f))
		.addAnimPoint(7, speed * 7.5f, Vec3(TORADIANS(-45.f), 0.f, 0.f))
		.addAnimPoint(7, speed * 10.f, Vec3(0.f, 0.f, 0.f))
		// Jambe Gauche
		.addAnimPoint(4, speed * 2.f, Vec3(TORADIANS(-20.f), TORADIANS(10.f), 0.f))
		.addAnimPoint(4, speed * 4.f, Vec3(0.f, TORADIANS(-10.f), TORADIANS(-10.f)))
		.addAnimPoint(4, speed * 6.f, Vec3(TORADIANS(7.5f), 0.f, 0.f))
		.addAnimPoint(4, speed * 8.f, Vec3(TORADIANS(15.f), 0.f, TORADIANS(30.f)))
		.addAnimPoint(4, speed * 10.f, Vec3(0.f, 0.f, 0.f))
		.addAnimPoint(5, speed * 2.f, Vec3(TORADIANS(30.f), 0.f, 0.f))
		.addAnimPoint(5, speed * 4.f, Vec3(TORADIANS(10.f), 0.f, 0.f))
		.addAnimPoint(5, speed * 6.f, Vec3(0.f, 0.f, 0.f))
		.addAnimPoint(5, speed * 8.f, Vec3(TORADIANS(30.f), 0.f, 0.f))
		.addAnimPoint(5, speed * 10.f, Vec3(0.f, 0.f, 0.f))

		// Jambe Droite
		.addAnimPoint(8, speed * 2.f, Vec3(TORADIANS(-20.f), TORADIANS(-10.f), 0.f))
		.addAnimPoint(8, speed * 4.f, Vec3(0.f, TORADIANS(10.f), TORADIANS(10.f)))
		.addAnimPoint(8, speed * 6.f, Vec3(TORADIANS(-7.5f), 0.f, 0.f))
		.addAnimPoint(8, speed * 8.f, Vec3(TORADIANS(-15.f), 0.f, TORADIANS(-30.f)))
		.addAnimPoint(8, speed * 10.f, Vec3(0.f, 0.f, 0.f))
		.addAnimPoint(9, speed * 2.f, Vec3(TORADIANS(30.f), 0.f, 0.f))
		.addAnimPoint(9, speed * 4.f, Vec3(TORADIANS(10.f), 0.f, 0.f))
		.addAnimPoint(9, speed * 6.f, Vec3(0.f, 0.f, 0.f))
		.addAnimPoint(9, speed * 8.f, Vec3(TORADIANS(30.f), 0.f, 0.f))
		.addAnimPoint(9, speed * 10.f, Vec3(0.f, 0.f, 0.f))
	;
	return (anim);
}

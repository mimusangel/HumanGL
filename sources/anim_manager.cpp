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
	Anim	anim(10);
	float	speed = 0.1f;

	anim.setLoop(true);
	//bras
	anim.addAnimPoint(2, speed * 0.5, Vec3(TORADIANS(60), 0, 0));
	anim.addAnimPoint(2, speed * 1.5, Vec3(TORADIANS(-60), 0, 0));
	anim.addAnimPoint(2, speed * 2, Vec3(0, 0, 0));
	anim.addAnimPoint(6, speed * 0.5, Vec3(TORADIANS(-60), 0, 0));
	anim.addAnimPoint(6, speed * 1.5, Vec3(TORADIANS(60), 0, 0));
	anim.addAnimPoint(6, speed * 2, Vec3(0, 0, 0));
	//jambe
	anim.addAnimPoint(4, speed * 0.5, Vec3(TORADIANS(-60), 0, 0));
	anim.addAnimPoint(4, speed * 1, Vec3(0, 0, 0));
	anim.addAnimPoint(4, speed * 2, Vec3(0, 0, 0));
	anim.addAnimPoint(5, speed * 0.5, Vec3(TORADIANS(60), 0, 0));
	anim.addAnimPoint(5, speed * 1, Vec3(0, 0, 0));
	anim.addAnimPoint(5, speed * 2, Vec3(0, 0, 0));
	anim.addAnimPoint(8, speed * 1, Vec3(0, 0, 0));
	anim.addAnimPoint(8, speed * 1.5, Vec3(TORADIANS(-60), 0, 0));
	anim.addAnimPoint(8, speed * 2, Vec3(0, 0, 0));
	anim.addAnimPoint(9, speed * 1, Vec3(0, 0, 0));
	anim.addAnimPoint(9, speed * 1.5, Vec3(TORADIANS(60), 0, 0));
	anim.addAnimPoint(9, speed * 2, Vec3(0, 0, 0));
	return (anim);
}

Anim	AnimManager::loadRun()
{
	Anim	anim(10);

	return (anim);
}

Anim	AnimManager::loadJump()
{
	Anim	anim(10);

	return (anim);
}

Anim	AnimManager::loadTwerk()
{
	Anim	anim(10);

	return (anim);
}

Anim	AnimManager::loadCrouch()
{
	Anim	anim(10);

	return (anim);
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
	Anim	anim(10);

	return (anim);
}

Anim AnimManager::loadNeo()
{
	Anim	anim(10);
	//body
	anim.addAnimPoint(-1, 0.5, Vec3(0, -0.1, -0.25));
	anim.addAnimPoint(-1, 2, Vec3(0, -0.1, -0.25));
	// anim.addAnimPoint(-1, 2, Vec3(0, 0, 0));
	anim.addAnimPoint(0, 0.5, Vec3(TORADIANS(-90), 0, 0));
	anim.addAnimPoint(0, 2, Vec3(TORADIANS(-90), 0, 0));
	// anim.addAnimPoint(0, 2, Vec3(TORADIANS(0), 0, 0));
	//bras
	anim.addAnimPoint(2, 0.5, Vec3(TORADIANS(-180), TORADIANS(-90), TORADIANS(0)));
	anim.addAnimPoint(6, 0.5, Vec3(TORADIANS(-180), TORADIANS(90), TORADIANS(0)));
	anim.addAnimPoint(2, 1, Vec3(TORADIANS(-180), TORADIANS(90), TORADIANS(0)));
	anim.addAnimPoint(6, 1, Vec3(TORADIANS(-180), TORADIANS(-90), TORADIANS(0)));
	//jambe
	anim.addAnimPoint(4, 0.5, Vec3(TORADIANS(45), TORADIANS(10), TORADIANS(-10)));
	anim.addAnimPoint(4, 2, Vec3(TORADIANS(45), TORADIANS(10), TORADIANS(-10)));
	anim.addAnimPoint(8, 0.5, Vec3(TORADIANS(45), TORADIANS(-10), TORADIANS(10)));
	anim.addAnimPoint(8, 2, Vec3(TORADIANS(45), TORADIANS(-10), TORADIANS(10)));

	anim.addAnimPoint(5, 0.5, Vec3(TORADIANS(45), TORADIANS(10), 0));
	anim.addAnimPoint(5, 2, Vec3(TORADIANS(45), TORADIANS(10), 0));
	anim.addAnimPoint(9, 0.5, Vec3(TORADIANS(45), TORADIANS(-10), 0));
	anim.addAnimPoint(9, 2, Vec3(TORADIANS(45), TORADIANS(-10), 0));

	return (anim);
}

Anim AnimManager::loadCloClo()
{
	Anim	anim(10);

	return (anim);
}

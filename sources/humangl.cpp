#include <iostream>
using namespace std;

#include "window.hpp"
#include "shaders.hpp"
#include "mesh.hpp"
#include "debug.hpp"
#include "transform.hpp"
#include "camera.hpp"
#include "cube.hpp"
#include "human.hpp"
#include "anim.hpp"
using namespace mmatrix;

int main()
{
	if (!glfwInit())
		cout << "Erreur init glfw!" << endl;
	else
	{
		Window win(1280, 720, "HumanGL");
		glfwFocusWindow(win.getGLFW());
		if (win.getError().length() > 0)
			std::cout << win.getError() << endl;
		else
		{
			Shaders sample;
			if (!sample.loadFragmentShader("sample.frag"))
				return (0);
			if (!sample.loadVertexShader("sample.vert"))
				return (0);
			if (!sample.build())
				return (0);

			glEnable(GL_DEPTH_TEST);
			glEnable(GL_CULL_FACE);
			glCullFace(GL_FRONT);

			Cube::Load();
			Human human;
			Camera	cam(win);
			// Anim	anim(10);
			Anim	anim = AnimManager::loadWalk();
			// Anim	anim = AnimManager::loadNeo();
			anim.setLoop(true);

			/*anim.addAnimPoint(-1, 1, Vec3(0, 0, 1));
			anim.addAnimPoint(-1, 2, Vec3(0, 0, 0));
			anim.addAnimPoint(0, 1, Vec3(0, TORADIANS(90), 0));
			anim.addAnimPoint(0, 2, Vec3(0, TORADIANS(0), 0));
			anim.addAnimPoint(2, 1, Vec3(0, 0, TORADIANS(-90)));
			anim.addAnimPoint(2, 2, Vec3(0, 0, TORADIANS(0)));
			anim.addAnimPoint(3, 1, Vec3(0, 0, TORADIANS(90)));
			anim.addAnimPoint(3, 2, Vec3(0, 0, TORADIANS(0)));*/
			human.setAnim(&anim);
			cam.translate(Vec3(0, 0, -2));
			while (win.isOpen())
			{
				/* ******************** */
				/* * UPDATE           * */
				/* ******************** */
				if (glfwGetMouseButton(win.getGLFW(), GLFW_MOUSE_BUTTON_MIDDLE) == GLFW_PRESS)
					human.setAnim(&anim);

				cam.move();
				if (glfwGetMouseButton(win.getGLFW(), GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS ||
					win.isGrabbed())
				{
					if (win.dirMouseSmooth != Vec2(0))
					{
						static Vec2	euler;
						euler += win.dirMouseSmooth;
						win.dirMouseSmooth = Vec2(0);
						cam.setRotate(Vec3(TORADIANS(euler), 0));
					}
				}
				human.update(glfwGetTime());
				/* ******************** */
				/* * RENDU            * */
				/* ******************** */
				win.makeContextCurrent();
				glClearColor(0.5, 0.5, 0.5, 1);
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
				sample.bind();
				sample.uniformMat4((GLchar *)"projection", (GLfloat *)&win.matProjection);
				Mat4x4 viewMat = cam.toMatrix();
				sample.uniformMat4((GLchar *)"view", (GLfloat *)&viewMat);
				human.render(sample);
				win.update();
			}
		}
	}
	Cube::Unload();
	return (0);
}

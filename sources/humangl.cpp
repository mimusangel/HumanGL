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
			Anim	animList[8] = {
				AnimManager::loadIdle(),
				AnimManager::loadWalk(0.2),
				AnimManager::loadRun(),
				AnimManager::loadJump(),
				AnimManager::loadCrouch(),
				AnimManager::loadMasturbate(),
				AnimManager::loadNeo(),
				AnimManager::loadCloClo()
			};
			// Anim	anim = AnimManager::loadWalk(0.2);
			// Anim	anim = AnimManager::loadNeo();
			// anim.setLoop(true);
			// human.setAnim(&anim);
			human.setAnim(&animList[0]);
			cam.translate(Vec3(2, 1.5, 2));
			cam.setRotateEuler(Vec3(TORADIANS(-135), TORADIANS(30), 0));
			while (win.isOpen())
			{
				/* ******************** */
				/* * UPDATE           * */
				/* ******************** */
				if (glfwGetKey(win.getGLFW(), GLFW_KEY_1))
					human.setAnim(animList);
				if (glfwGetKey(win.getGLFW(), GLFW_KEY_2))
					human.setAnim(animList + 1);
				if (glfwGetKey(win.getGLFW(), GLFW_KEY_3))
					human.setAnim(animList + 2);
				if (glfwGetKey(win.getGLFW(), GLFW_KEY_4))
					human.setAnim(animList + 3);
				if (glfwGetKey(win.getGLFW(), GLFW_KEY_5))
					human.setAnim(animList + 4);
				if (glfwGetKey(win.getGLFW(), GLFW_KEY_6))
					human.setAnim(animList + 5);
				if (glfwGetKey(win.getGLFW(), GLFW_KEY_7))
					human.setAnim(animList + 6);
				if (glfwGetKey(win.getGLFW(), GLFW_KEY_8))
					human.setAnim(animList + 7);

				// if (glfwGetMouseButton(win.getGLFW(), GLFW_MOUSE_BUTTON_MIDDLE) == GLFW_PRESS)
				// 	human.setAnim(&anim);

				cam.move();
				if (glfwGetMouseButton(win.getGLFW(), GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS ||
					win.isGrabbed())
					cam.rotateEuler(Vec3(TORADIANS(win.dirMouse), 0));
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

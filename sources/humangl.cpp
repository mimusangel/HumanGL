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
			Anim	animList[8] = {
				AnimManager::loadIdle(0.5),
				AnimManager::loadWalk(0.2),
				AnimManager::loadRun(0.2),
				AnimManager::loadJump(0.2),
				AnimManager::loadCrouch(0.5),
				AnimManager::loadMasturbate(0.2),
				AnimManager::loadNeo(),
				AnimManager::loadCloClo(0.5)
			};
			human.setAnim(&animList[0]);
			cam.translate(Vec3(2, 1.5, 2));
			cam.setRotateEuler(Vec3(TORADIANS(-135), TORADIANS(30), 0));
			win.human = &human;
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
				{
					human.setAnim(animList + 5);
					human.getParts(14).getRot() = Vec3(TORADIANS(-45.f), 0.0f, 0.0f);
				}
				if (glfwGetKey(win.getGLFW(), GLFW_KEY_7))
					human.setAnim(animList + 6);
				if (glfwGetKey(win.getGLFW(), GLFW_KEY_8))
					human.setAnim(animList + 7);
				if (glfwGetKey(win.getGLFW(), GLFW_KEY_9))
					human.setAnim(nullptr);
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

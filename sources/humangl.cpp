#include <iostream>
using namespace std;

#include "window.hpp"
#include "shaders.hpp"
#include "mesh.hpp"
#include "debug.hpp"
#include "transform.hpp"
#include "camera.hpp"
#include "cube.hpp"
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
			Cube::Load();

			// Mat4x4	model_right_leg = Mat4x4::Translate(Vec3(0.0625f, 0.375f, 0));
			// model_right_leg.scale_aniso(Vec3(0.125f, 0.375f, 0.125f));
			// model_right_leg.translate_in_place(Vec3(0.0f, -0.5f, 0.0f));
			// Mat4x4	model_left_leg = Mat4x4::Translate(Vec3(-0.0625f, 0.375f, 0));
			// model_left_leg.scale_aniso(Vec3(0.125f, 0.375f, 0.125f));
			// model_left_leg.translate_in_place(Vec3(0.0f, -0.5f, 0.0f));
			// Mat4x4	model_right_arm = Mat4x4::Translate(Vec3(-0.1875f, 0.750f, 0));
			// model_right_arm.scale_aniso(Vec3(0.125f, 0.375f, 0.125f));
			// model_right_arm.translate_in_place(Vec3(0.0f, -0.5f, 0.0f));
			// Mat4x4	model_left_arm = Mat4x4::Translate(Vec3(0.1875f, 0.750f, 0));
			// model_left_arm.scale_aniso(Vec3(0.125f, 0.375f, 0.125f));
			// model_left_arm.translate_in_place(Vec3(0.0f, -0.5f, 0.0f));
			Cube body(Vec3(0, 0.375f, 0), Vec3(), Vec3(0.0f, 0.5f, 0.0f), Vec3(0.25f, 0.375f, 0.125f));
			Cube head(Vec3(0, -0.125f, 0), Vec3(), Vec3(0.0f, 0.5f, 0.0f), Vec3(0.25f));
			head.setParent(&body);
			Cube leftArmUp(Vec3(0.125f + 0.0625f, -0.125f - 0.03125f, 0.f), Vec3(), Vec3(0, -0.333f, 0.f), Vec3(0.125f, 0.1875f, 0.125f));
			leftArmUp.setParent(&body);

			/*
			0.1875f  =  1.5f       1.25  = 0.15625f
			0.125f      1.f

			*/

			Vec3	rot;
			Vec3	rot2;

			glEnable(GL_DEPTH_TEST);
			glEnable(GL_CULL_FACE);
			glCullFace(GL_FRONT);
			// Debug::print(model);
			Camera	cam(win);

			cam.translate(Vec3(0, 0, -2));
			Vec3 right(1, 0, 0);
			Vec3 up(0, 1, 0);
			while (win.isOpen())
			{
				/* ******************** */
				/* * UPDATE           * */
				/* ******************** */
				rot[1] += 0.01f;
				rot2[2] = TORADIANS(90);
				head.setRotate(rot);
				leftArmUp.setRotate(rot2);
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
						// cam.rotate(up, TORADIANS(win.dirMouse[0]));
						// cam.rotate(right, TORADIANS(win.dirMouse[1]));
					}
					// Debug::print(win.dirMouse);
				}
				// cam_move(win, cam);
				/* ******************** */
				/* * RENDU            * */
				/* ******************** */
				win.makeContextCurrent();
				glClearColor(0.5, 0.5, 0.5, 1);
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
				sample.bind();
				sample.uniformMat4((GLchar *)"projection", (GLfloat *)&win.matProjection);
				Mat4x4 viewMat = cam.toMatrix();
				// Debug::print(viewMat);
				sample.uniformMat4((GLchar *)"view", (GLfloat *)&viewMat);
				Mat4x4 model = body.toMatrix();
				sample.uniformMat4((GLchar *)"model", (GLfloat *)&model);
				Cube::Render();
				model = head.toMatrix();
				sample.uniformMat4((GLchar *)"model", (GLfloat *)&model);
				Cube::Render();
				model = leftArmUp.toMatrix();
				sample.uniformMat4((GLchar *)"model", (GLfloat *)&model);
				Cube::Render();

				// sample.uniformMat4((GLchar *)"model", (GLfloat *)&model_body);
				// Cube::Render();
				// sample.uniformMat4((GLchar *)"model", (GLfloat *)&model_head);
				// Cube::Render();
				// sample.uniformMat4((GLchar *)"model", (GLfloat *)&model_right_leg);
				// Cube::Render();
				// sample.uniformMat4((GLchar *)"model", (GLfloat *)&model_left_leg);
				// Cube::Render();
				// sample.uniformMat4((GLchar *)"model", (GLfloat *)&model_right_arm);
				// Cube::Render();
				// sample.uniformMat4((GLchar *)"model", (GLfloat *)&model_left_arm);
				// Cube::Render();
				win.update();
			} // GL_LINE_STRIP
		}
	}
	Cube::Unload();
	return (0);
}

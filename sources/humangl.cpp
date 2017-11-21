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

			Cube body(Vec3(0, 0.375f, 0),	Vec3(),	Vec3(0.0f, 0.5f, 0.0f), Vec3(0.25f, 0.375f, 0.125f));
			Cube head(Vec3(0, 1, 0),	Vec3(), 	Vec3(0.0f, 0.5f, 0.0f), Vec3(0.25f));
			Cube leftArmUp(Vec3(-0.5, 1, 0),	Vec3(),	Vec3(-0.5, -0.5, 0.f), Vec3(0.1249f, 0.1875f, 0.1249f));
			Cube leftArmDown(Vec3(-0.5, -1, 0),	Vec3(),	Vec3(0, -0.5, 0), Vec3(0.1249f, 0.1875f, 0.1249f));
			Cube leftLegUp(Vec3(-0.25, 0, 0),	Vec3(),	Vec3(0, -0.5, 0.f), Vec3(0.1249f, 0.1875f, 0.1249f));
			Cube leftLegDown(Vec3(0, -1, 0),	Vec3(),	Vec3(0, -0.5, 0), Vec3(0.1249f, 0.1875f, 0.1249f));
			Cube rightArmUp(Vec3(0.5, 1, 0),	Vec3(),	Vec3(0.5, -0.5, 0.f), Vec3(0.1249f, 0.1875f, 0.1249f));
			Cube rightArmDown(Vec3(0.5, -1, 0),	Vec3(),	Vec3(0, -0.5, 0), Vec3(0.1249f, 0.1875f, 0.1249f));
			Cube rightLegUp(Vec3(0.25, 0, 0),	Vec3(),	Vec3(0, -0.5, 0.f), Vec3(0.1249f, 0.1875f, 0.1249f));
			Cube rightLegDown(Vec3(0, -1, 0),	Vec3(),	Vec3(0, -0.5, 0), Vec3(0.1249f, 0.1875f, 0.1249f));
			head.setParent(&body);
			leftArmUp.setParent(&body);
			leftArmDown.setParent(&leftArmUp);
			leftLegUp.setParent(&body);
			leftLegDown.setParent(&leftLegUp);
			rightArmUp.setParent(&body);
			rightArmDown.setParent(&rightArmUp);
			rightLegUp.setParent(&body);
			rightLegDown.setParent(&rightLegUp);

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
				rot2[2] += 0.01f;
				// rot2[2] = TORADIANS(90);
				head.setRotate(rot);
				leftArmUp.setRotate(rot2.negate());
				leftArmDown.setRotate(rot2.negate());
				leftLegUp.setRotate(rot2.negate());
				leftLegDown.setRotate(rot2.negate());
				rightArmUp.setRotate(rot2);
				rightArmDown.setRotate(rot2);
				rightLegUp.setRotate(rot2);
				rightLegDown.setRotate(rot2);
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
				model = leftArmDown.toMatrix();
				sample.uniformMat4((GLchar *)"model", (GLfloat *)&model);
				Cube::Render();
				model = leftLegUp.toMatrix();
				sample.uniformMat4((GLchar *)"model", (GLfloat *)&model);
				Cube::Render();
				model = leftLegDown.toMatrix();
				sample.uniformMat4((GLchar *)"model", (GLfloat *)&model);
				Cube::Render();
				model = rightArmUp.toMatrix();
				sample.uniformMat4((GLchar *)"model", (GLfloat *)&model);
				Cube::Render();
				model = rightArmDown.toMatrix();
				sample.uniformMat4((GLchar *)"model", (GLfloat *)&model);
				Cube::Render();
				model = rightLegUp.toMatrix();
				sample.uniformMat4((GLchar *)"model", (GLfloat *)&model);
				Cube::Render();
				model = rightLegDown.toMatrix();
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

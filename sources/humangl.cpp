#include <iostream>
using namespace std;

#include "window.hpp"
#include "shaders.hpp"
#include "mesh.hpp"
#include "debug.hpp"
#include "transform.hpp"
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
			Mesh mesh(2);
			if (mesh.isCreated())
			{
				mesh.begin();
				// static const GLfloat g_vertex_buffer_data[] = {
				//    -1.0f, -1.0f, 0.0f,
				//    0.0f,  1.0f, 0.0f,
				//    1.0f, -1.0f, 0.0f,
				// };
				// mesh.add(0, GL_FLOAT, 3, (void *)g_vertex_buffer_data, 3);
				// mesh.end();

				static const GLfloat g_vertex_buffer_data[] = {
					0, 1, 0, 1, 1, 0, 0, 0, 0,
					1, 0, 0, 0, 0, 0, 1, 1, 0,
					0, 1, 1, 0, 0, 1, 1, 1, 1,
					1, 0, 1, 1, 1, 1, 0, 0, 1,
					0, 1, 0, 0, 0, 0, 0, 1, 1,
					0, 0, 1, 0, 1, 1, 0, 0, 0,
					1, 1, 0, 1, 1, 1, 1, 0, 0,
					1, 0, 1, 1, 0, 0, 1, 1, 1,
					0, 1, 1, 1, 1, 1, 0, 1, 0,
					1, 1, 0, 0, 1, 0, 1, 1, 1,
					0, 0, 1, 0, 0, 0, 1, 0, 1,
					1, 0, 0, 1, 0, 1, 0, 0, 0
				};
				static const GLfloat g_color_buffer_data[] = {
					0, 0, 1, 0, 0, 1, 0, 0, 1,
					0, 1, 0, 0, 1, 0, 0, 1, 0,
					0, 1, 1, 0, 1, 1, 0, 1, 1,
					1, 0, 0, 1, 0, 0, 1, 0, 0,
					1, 0, 1, 1, 0, 1, 1, 0, 1,
					1, 1, 0, 1, 1, 0, 1, 1, 0,
					1, 1, 1, 1, 1, 1, 1, 1, 1,
					0, 0, 1, 0, 0, 1, 0, 0, 1,
					0, 1, 0, 0, 1, 0, 0, 1, 0,
					0, 1, 1, 0, 1, 1, 0, 1, 1,
					1, 0, 0, 1, 0, 0, 1, 0, 0,
					1, 0, 1, 1, 0, 1, 1, 0, 1
				};
				mesh.add(0, GL_FLOAT, 3, (void *)g_vertex_buffer_data, 36);
				mesh.add(1, GL_FLOAT, 3, (void *)g_color_buffer_data, 36);
				mesh.end();
			}
			//head		Vec3(0.25f, 0.25f, 0.25f);
			//body		Vec3(0.25f, 0.375f, 0.125f);
			//other		Vec3(0.125f, 0.375f, 0.125f);
			//other		Vec3(0.125f, 0.1875f, 0.125f);

			Mat4x4	perspective = Mat4x4::Perspective(70.0f, 1280.0f / 720.0f, 0.1f, 1000.0f);
			Mat4x4	model_head = Mat4x4::Translate(Vec3(0, 0.375f * 2, 0));
			model_head.scale_aniso(Vec3(0.25f, 0.25f, 0.25f));
			model_head.translate_in_place(Vec3(-0.5f, 0.0f, -0.5f));
			Mat4x4	model_body = Mat4x4::Translate(Vec3(0, 0.375f, 0));
			model_body.scale_aniso(Vec3(0.25f, 0.375f, 0.125f));
			model_body.translate_in_place(Vec3(-0.5f, 0.0f, -0.5f));
			Mat4x4	model_right_leg = Mat4x4::Translate(Vec3(0.0625f, 0.375f, 0));
			model_right_leg.scale_aniso(Vec3(0.125f, 0.375f, 0.125f));
			model_right_leg.translate_in_place(Vec3(-0.5f, -1.0f, -0.5f));
			glEnable(GL_DEPTH_TEST);
			glEnable(GL_CULL_FACE);
			glCullFace(GL_FRONT);
			// Debug::print(model);
			Transform cam;

			cam.translate(Vec3(0, 0, 2));
			Vec3 right(1, 0, 0);
			Vec3 up(0, 1, 0);
			while (win.isOpen())
			{
				/* ******************** */
				/* * UPDATE           * */
				/* ******************** */
				if (win.isGrabbed())
				{
					if (glfwGetKey(win.getGLFW(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
						win.setGrab(false);
					if (win.dirMouse[0] != 0.0f || win.dirMouse[0] != 0.0f)
					{
						static Vec2	euler;
						euler += win.dirMouse;
						cam.setRotate(Vec3(TORADIANS(euler), 0));
					}
					win.dirMouse[0] = 0;
					win.dirMouse[1] = 0;
					// Debug::print(win.dirMouse);
				}
				else
				{
					if (glfwGetMouseButton(win.getGLFW(), GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
						win.setGrab(true);
				}
				/* ******************** */
				/* * RENDU            * */
				/* ******************** */
				win.makeContextCurrent();
				glClearColor(0.5, 0.5, 0.5, 1);
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
				sample.bind();
				sample.uniformMat4((GLchar *)"projection", (GLfloat *)&perspective);
				Mat4x4 viewMat = cam.toMatrix();
				sample.uniformMat4((GLchar *)"view", (GLfloat *)&viewMat);
				sample.uniformMat4((GLchar *)"model", (GLfloat *)&model_body);
				mesh.render(GL_TRIANGLES);
				sample.uniformMat4((GLchar *)"model", (GLfloat *)&model_head);
				mesh.render(GL_TRIANGLES);
				sample.uniformMat4((GLchar *)"model", (GLfloat *)&model_right_leg);
				mesh.render(GL_TRIANGLES);
				win.update();
			} // GL_LINE_STRIP
		}
	}
	return (0);
}

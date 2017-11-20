#include <iostream>
using namespace std;

#include <mmatrix.hpp>
#include "window.hpp"
#include "shaders.hpp"
#include "mesh.hpp"

int main()
{
	if (!glfwInit())
		cout << "Erreur init glfw!" << endl;
	else
	{
		Window win(1280, 720, "HumanGL");
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
			Mesh mesh(1);
			if (mesh.isCreated())
			{
				mesh.begin();
				static const GLfloat g_vertex_buffer_data[] = {
				   -1.0f, -1.0f, -3.0f,
				   0.0f,  1.0f, -3.0f,
				   1.0f, -1.0f, -3.0f,
				};
				mesh.add(0, GL_FLOAT, 3, (void *)g_vertex_buffer_data, 3);
				mesh.end();
			}
			mmatrix::Mat4x4 perspective = mmatrix::Mat4x4::Perspective(70.0f, 1280.0f / 720.0f, 0.1f, 1000.0f);
			// glEnable(GL_DEPTH_TEST);
			glEnable(GL_CULL_FACE);
			glCullFace(GL_FRONT);
			GLfloat test[16] = {
				1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f
			};
			while (win.isOpen())
			{
				win.makeContextCurrent();
				sample.bind();
				sample.uniformMat4((GLchar *)"projection", (GLfloat *)&perspective);
				mesh.render(GL_TRIANGLES); // GL_LINE_STRIP
				win.update();
			}
		}
	}
	return (0);
}

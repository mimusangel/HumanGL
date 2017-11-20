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
				   -1.0f, -1.0f, 3.0f,
				   0.0f,  1.0f, 3.0f,
				   1.0f, -1.0f, 3.0f,
				};
				mesh.add(0, GL_FLOAT, 3, (void *)g_vertex_buffer_data, 3);
				mesh.end();
			}
			mmatrix::Mat4x4 perspective = mmatrix::Mat4x4::Perspective(70.0f, 1280.0f / 720.0f, 0.1f, 1000.0f);
			// glEnable(GL_DEPTH_TEST);
			glEnable(GL_CULL_FACE);
			glCullFace(GL_FRONT);
			/*GLfloat test[16] = {
				1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f
			};*/
			mmatrix::Mat4x4 cam = mmatrix::Mat4x4::Identity();
			mmatrix::Mat4x4	mvp;

			{
			const float	*a = (float*)&cam;
			int	i = 0;
			printf("mat : %f %f %f %f\n%f %f %f %f\n%f %f %f %f\n%f %f %f %f\n\n",
				a[i++],a[i++],a[i++],a[i++],a[i++],a[i++],a[i++],a[i++],a[i++],a[i++],a[i++],a[i++],a[i++],a[i++],a[i++],a[i++]);
			}
			// cam.translate_in_place(mmatrix::Vec3(1, 0.2, 0.3));
			// cam.set_translate(mmatrix::Vec3(0, 0, -1));
			// cam = cam.translate(mmatrix::Vec3(0, 0, -1));
			// cam.rotate_x(0.1f);
			// cam.rotate(mmatrix::Vec3(0, 1, 0), 0.1f);
			// cam[3][3] = 1;
			{
			const float	*a = (float*)&cam;
			int	i = 0;
			printf("mat : %f %f %f %f\n%f %f %f %f\n%f %f %f %f\n%f %f %f %f\n\n",
				a[i++],a[i++],a[i++],a[i++],a[i++],a[i++],a[i++],a[i++],a[i++],a[i++],a[i++],a[i++],a[i++],a[i++],a[i++],a[i++]);
			}
			while (win.isOpen())
			{
				static int tt;
				cam.rotate_x(0.01f * tt++);
				win.makeContextCurrent();
				sample.bind();
				mvp = perspective * cam;
				sample.uniformMat4((GLchar *)"projection", (GLfloat *)&mvp);
				mesh.render(GL_TRIANGLES); // GL_LINE_STRIP
				win.update();
			}
		}
	}
	return (0);
}

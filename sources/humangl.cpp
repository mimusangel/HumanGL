#include <iostream>
using namespace std;

#include "window.hpp"
#include "shaders.hpp"

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


			GLuint VertexArrayID;
			glGenVertexArrays(1, &VertexArrayID);
			glBindVertexArray(VertexArrayID);
			static const GLfloat g_vertex_buffer_data[] = {
			   -1.0f, -1.0f, 0.0f,
			   1.0f, -1.0f, 0.0f,
			   0.0f,  1.0f, 0.0f,
			};
			GLuint vertexbuffer;
			glGenBuffers(1, &vertexbuffer);
			glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
			glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindVertexArray(0);


			while (win.isOpen())
			{
				win.makeContextCurrent();

				
				sample.bind();
				glBindVertexArray(VertexArrayID);
				glDrawArrays(GL_TRIANGLES, 0, 3);
				glBindVertexArray(0);


				win.update();
			}
		}
	}
	return (0);
}

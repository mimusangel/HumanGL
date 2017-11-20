#version 330 core
layout(location = 0) in vec3 vertexPosition;

uniform mat4 projection;
uniform mat4 model;

void main()
{
	mat4 mvp = projection * model;
	gl_Position = mvp * vec4(vertexPosition, 1);
}

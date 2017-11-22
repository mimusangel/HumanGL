#version 330 core

out vec4 color;

uniform vec3 uColor;

in vec3 vColor;

void main(){
	color = vec4(vColor * uColor, 1.0);
}

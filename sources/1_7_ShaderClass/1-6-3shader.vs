#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

//out vec3 ourColor;
out vec3 ourPosition;

uniform float xOffset;	// exercise2, move the triangle to the right of the screen using this offset value

void main() {
	gl_Position = vec4(aPos, 1.0);
	// gl_Position = vec4(aPos.x + xOffset, -aPos.y, aPos.z, 1.0); // exercise1, just add a - to the y position
	ourPosition = aPos;
	//ourColor = aColor;
}
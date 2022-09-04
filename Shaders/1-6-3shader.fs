#version 330 core
//in vec3 ourColor;
in vec3 ourPosition;
out vec4 FragColor;

void main() {
	FragColor = vec4(ourPosition, 1.0f); // exercise3, note how the position value is linearly interpolated to get all the different colors
}
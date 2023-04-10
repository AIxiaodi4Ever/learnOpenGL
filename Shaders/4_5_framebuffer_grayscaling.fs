#version 330 core

in vec2 TexCoords;

out vec4 FragColor;

uniform sampler2D screenTexture;

const vec3 weight = vec3(0.2126, 0.7152, 0.0722);

void main() {
  FragColor = texture(screenTexture, TexCoords);
  float avgColor = dot(weight, vec3(FragColor));
  FragColor = vec4(vec3(avgColor), 1.0);
}
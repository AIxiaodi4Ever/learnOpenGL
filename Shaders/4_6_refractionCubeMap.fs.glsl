#version 330 core
out vec4 FragColor;

in vec3 Postion;
in vec3 Normal;

uniform vec3 cameraPos;
uniform samplerCube skybox;

void main() {
  float ratio = 1.0 / 1.52;
  vec3 I = normalize(Postion - cameraPos);
  vec3 NormalCorrected = dot(I, Normal) < 0 ? Normal : -Normal;
  vec3 R = refract(I, NormalCorrected, ratio);
  FragColor = vec4(texture(skybox, R).rgb, 1.0);
}
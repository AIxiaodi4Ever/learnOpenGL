#version 330 core
out vec4 FragColor;

in vec3 Postion;
in vec3 Normal;

uniform vec3 cameraPos;
uniform samplerCube skybox;
uniform sampler2D innerTexture;

void main() {
  vec3 I = normalize(Postion - cameraPos);
  vec3 R = reflect(I, normalize(Normal));
  FragColor = vec4(texture(skybox, R).rgb, 1.0);
  if (all(lessThan(cameraPos, vec3(0.5))) && all(greaterThan(cameraPos, vec3(-0.5)))) {
    FragColor = vec4(texture(innerTexture, abs(R.xy)).rgb, 1.0);
  }
}
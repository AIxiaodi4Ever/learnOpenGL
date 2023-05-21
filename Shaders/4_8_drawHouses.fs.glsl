#version 420 core

out vec4 FragOutColor;

in GS_OUT {
  vec3 fColor;
} fs_in;

void main() {
  FragOutColor = vec4(fs_in.fColor, 1.0);
}
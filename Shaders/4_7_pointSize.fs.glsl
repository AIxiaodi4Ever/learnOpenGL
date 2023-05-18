#version 330 core
out vec4 outFragColor;

in vec4 Position;

void main() {
  outFragColor.x = (Position.x > 0.0) ? 1.0 : 0.0;
  outFragColor.y = (Position.y > 0.0) ? 1.0 : 0.0;
  outFragColor.z = (Position.z > 0.0) ? 1.0 : 0.0;
  // outFragColor.rgb = vec3(1.0);
  outFragColor.w = 1.0;
}
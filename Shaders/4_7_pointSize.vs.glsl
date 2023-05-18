#version 330 core
layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;

out vec4 Position;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
  Position = vec4(position, 1.0);
  gl_Position = projection * view * model * vec4(position, 1.0);
  // gl_PointSize = gl_Position.z;
  gl_PointSize = 50.0;
}

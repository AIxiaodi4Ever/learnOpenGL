#version 420 core
layout(location = 0) in vec3 pos;
layout(location = 1) in vec3 norm;

layout(std140, binding = 0) uniform Matrices {
  mat4 projection;
  mat4 view;
};

uniform mat4 model;

out VS_OUT {
  vec3 pos;
  vec3 norm;
} vs_out;

void main() {
  vs_out.pos = pos;
  vs_out.norm = norm;
  gl_Position = projection * view * model * vec4(pos, 1.0);
}

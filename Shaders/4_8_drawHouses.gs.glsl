#version 420 core
layout(points) in;
layout(triangle_strip, max_vertices = 5) out;

in VS_OUT {
 vec3 aColor;
} gs_in[];

out GS_OUT {
  vec3 fColor;
} gs_out;

void build_house(vec4 position) {
  gs_out.fColor = gs_in[0].aColor;
  gl_Position = position + vec4(-0.2, -0.2, 0.0, 0.0);
  EmitVertex();
  gl_Position = position + vec4(0.2, -0.2, 0.0, 0.0);
  EmitVertex();
  gl_Position = position + vec4(-0.2, 0.2, 0.0, 0.0);
  EmitVertex();
  gl_Position = position + vec4(0.2, 0.2, 0.0, 0.0);
  EmitVertex();
  gl_Position = position + vec4(0.0, 0.4, 0.0, 0.0);
  gs_out.fColor = vec3(1.0);
  EmitVertex();
  EndPrimitive();
}

void main() {
  build_house(gl_in[0].gl_Position);
}

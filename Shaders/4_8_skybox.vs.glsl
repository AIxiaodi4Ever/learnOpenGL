#version 420 core
layout (location = 0) in vec3 aPos;

out vec3 TexCoords;

layout(std140, binding = 0) uniform Matrices {
    mat4 projection;
    mat4 view;
};

void main()
{
    TexCoords = aPos;
    vec4 pos = projection * view * vec4(aPos, 1.0);
    // in this way, sky box will always behind all object with the depth 1
    gl_Position = pos.xyww; 
}  
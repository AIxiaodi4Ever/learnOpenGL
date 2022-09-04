#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec2 aTexCoords;
layout(location = 3) in vec2 SpecTexCoords;
layout(location = 4) in vec2 EmisTexCoords;

out vec3 FragPos;
out vec3 Normal;
out vec2 TexCoords;
out vec2 specTexCoords;
out vec2 emisTexCoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() 
{
	FragPos = vec3(model * vec4(aPos, 1.0f));
	Normal = mat3(transpose(inverse(model))) * aNormal;
	TexCoords = aTexCoords;
	specTexCoords = SpecTexCoords;
	emisTexCoords = EmisTexCoords;

	gl_Position = projection * view * model * vec4(aPos, 1.0f);
}	
#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;

out vec3 LightingColor; // resulting color from lighting calculation

out vec3 FragPos;
out vec3 Normal;
out vec3 ViewLightPos;

uniform vec3 lightPos;	// define a view space coordiantes for lightPos
uniform vec3 lightColor;
uniform vec3 viewPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() 
{
	/*
	FragPos = vec3(model * vec4(aPos, 1.0f));
	Normal = aNormal;
	gl_Position = projection * view * vec4(FragPos, 1.0f);
	*/

	/*
	// calculate light in view space
	FragPos = vec3(view * model * vec4(aPos, 1.0f));
	ViewLightPos = vec3(view * vec4(lightPos, 1.0f));
	Normal = mat3(transpose(inverse(view * model))) * aNormal;
	gl_Position = projection * vec4(FragPos, 1.0f);
	*/

	// calculate light in vertex shader, in world space
	gl_Position = projection * view * model * vec4(aPos, 1.0f);

	vec3 Position = vec3(model * vec4(aPos, 1.0f));
	vec3 Normal = mat3(transpose(inverse(model))) * aNormal;

	// ambient
	float ambientStrength = 0.1;
	vec3 ambient = ambientStrength * lightColor;

	// diffuse
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(lightPos - Position);
	float diff = max(dot(norm, lightDir), 0.0f);
	vec3 diffuse = diff * lightColor;

	// specular
	float specularStrength = 1.0; // this is set higher to better show the effect of Gouraud shading
	vec3 viewDir = normalize(viewPos - Position);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0f), 32);
	vec3 specular = specularStrength * spec * lightColor;

	LightingColor = ambient + diffuse + specular;
}	
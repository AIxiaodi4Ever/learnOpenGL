#version 330 core

struct Material {
	sampler2D diffuse;
	sampler2D specular;
	sampler2D emission;
	float shininess;
};

struct Light {
	//vec3 direction;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;

	/*
	float constant;
	float linear;
	float quadratic;
	*/

	vec3 position;
	vec3 direction;
	float cutOff;
	float outerCutOff;
};

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;
in vec2 specTexCoords;
in vec2 emisTexCoords;

out vec4 FragColor;

uniform vec3 viewPos;
uniform Material material;
uniform Light light;

void main() 
{
	/*
	float distance = length(light.position - FragPos);
	float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * distance * distance);
	*/

	vec3 lightDir = normalize(light.position - FragPos);
	float theta = dot(lightDir, normalize(-light.direction));
	float epsilon = light.cutOff - light.outerCutOff;
	float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0, 1.0);

	vec3 result = vec3(0.0f);

	// ambient
	vec3 ambient = light.ambient * vec3(texture(material.diffuse, TexCoords));
	//ambient *= attenuation;

	// diffuse
	vec3 norm = normalize(Normal);
	//vec3 lightDir = normalize(-light.direction);
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, TexCoords));
	diffuse *= intensity;
	//diffuse *= attenuation;

	// specular
	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
	vec3 specular = light.specular * spec * vec3(texture(material.specular, specTexCoords));
	specular *= intensity;
	//specular *= attenuation;

	result += ambient + diffuse + specular;

	vec3 emission = vec3(texture(material.emission, TexCoords));
	FragColor = vec4(result + emission, 1.0);
}

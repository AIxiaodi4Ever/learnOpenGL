#version 420 core
out vec4 FragColor;

in vec3 TexCoords;

uniform samplerCube skybox;

void main()
{    
    FragColor = texture(skybox, TexCoords);
    // FragColor = vec4((TexCoords + vec3(1.0)) * 0.5, 1.0);
}
// fragment shader
#version 460 core
out vec4 FragColor;
in  vec2 TexCoords;
  
uniform sampler2D fboAttachment;
  
void main()
{
    vec3 fboColor = texture(fboAttachment, TexCoords).rgb;
    FragColor = vec4(fboColor, 1.0);
}
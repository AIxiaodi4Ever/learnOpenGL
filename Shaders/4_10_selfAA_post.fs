#version 460 core

in vec2 TexCoords;

uniform sampler2DMS screenTextureMS;

out vec4 FragColor; 

void main() {
    int sampleNums = textureSamples(screenTextureMS);
    ivec2 texturePosition = ivec2(gl_FragCoord.x, gl_FragCoord.y);
    vec4 col = vec4(0.0);
    for (int i = 0; i < sampleNums; i++) {
        col += texelFetch(screenTextureMS, texturePosition, i) / float(sampleNums);
    }
    float grayscale = 0.2126 * col.r + 0.7152 * col.g + 0.0722 * col.b;
    FragColor = vec4(vec3(grayscale), 1.0);
}
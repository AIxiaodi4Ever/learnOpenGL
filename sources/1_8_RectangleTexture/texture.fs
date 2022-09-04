#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

// texture sampler
uniform sampler2D texture1;
uniform sampler2D texture2;
uniform float mixValue;

void main() {
	//FragColor = texture(texture1, TexCoord) * vec4(ourColor, 1.0);
	// linear interpolate between both textures (80% the first, 20% the second)
	//FragColor = mix(texture(texture1, TexCoord), texture(texture2, TexCoord), 0.2);
	//FragColor = mix(texture(texture1, TexCoord), texture(texture2, vec2(1 - TexCoord.x, TexCoord.y)), 0.2); // exercise 1
	//FragColor = mix(texture(texture1, TexCoord), texture(texture2, 2 * TexCoord), 0.2);	// exercise 2
	FragColor = mix(texture(texture1, TexCoord), texture(texture2, TexCoord), mixValue);
}

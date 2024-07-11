#version 460 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;
layout (location = 3) in vec3 aTangent;
layout (location = 4) in vec3 aBitangent;

out VS_OUT {
    vec3 FragPos;
    vec2 TexCoords;
    vec3 TangentLightPos;
    vec3 TangentViewPos;
    vec3 TangentFragPos;
    // for compare with normal map
    vec3 outN;

    // debug code
    // vec3 outT;
    // vec3 outB;
    // vec3 outTangent;
    // vec3 outBitangent;
    // mat3 outNormalMatrix;
    // mat3 outModelMatrix;
} vs_out;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

uniform vec3 lightPos;
uniform vec3 viewPos;

void main()
{
    vs_out.FragPos = vec3(model * vec4(aPos, 1.0));   
    vs_out.TexCoords = aTexCoords;
    
    mat3 normalMatrix = transpose(inverse(mat3(model)));
    vec3 T = normalize(normalMatrix * aTangent);
    vec3 N = normalize(normalMatrix * aNormal);
    T = normalize(T - dot(T, N) * N);
    vec3 B = cross(N, T);
    
    mat3 TBN = transpose(mat3(T, B, N));    
    vs_out.TangentLightPos = TBN * lightPos;
    vs_out.TangentViewPos  = TBN * viewPos;
    vs_out.TangentFragPos  = TBN * vs_out.FragPos;
    vs_out.outN = N;
        
    gl_Position = projection * view * model * vec4(aPos, 1.0);

    // debug code
    // vs_out.outT = T;
    // vs_out.outB = B;
    // vs_out.outN = N;
    // vs_out.outTangent = aTangent;
    // vs_out.outBitangent = aBitangent;
    // vs_out.outNormalMatrix = normalMatrix;
    // vs_out.outModelMatrix = mat3(model); 
}
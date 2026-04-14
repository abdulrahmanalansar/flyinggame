#shader vertex   
    
#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCord;
layout (location = 2) in vec3 aNormal;

out vec3 FragPos;
out vec3 Normal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 afragcolor;
void main()
{
    FragPos = vec3(model * vec4(aPos, 1.0));
    Normal = mat3(transpose(inverse(model))) * aNormal;
    gl_Position = projection * view * vec4(FragPos, 1.0);
   
    // Logic based on vertex height (aPos.y)
    if(aPos.z > 3.1)
    {
        // Snow
        afragcolor = vec3(0.98, 0.98, 1.0);
    }
    else if(aPos.z > 0.5)
    {
        // Grass
        afragcolor = vec3(0.294, 0.545, 0.231);
    }
    else
    {
        // Soil
        afragcolor = vec3(0.251, 0.161, 0.019);
    }

}

#shader fragment
   
#version 330 core

in vec3 FragPos;
in vec3 Normal;

out vec4 FragColor;

uniform vec3 lightPos;
uniform vec3 lightColor;
in vec3 afragcolor;
uniform vec3 viewPos;
uniform sampler2D u_Texture;

void main()
{
     // Ambient
    float ambientStrength = 0.2;
    vec3 ambient = ambientStrength * lightColor;

    // Diffuse
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    // Specular
    float specularStrength = 0.5;
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * lightColor;

    vec3 result = (ambient + diffuse + specular) * afragcolor;
    FragColor = vec4(result, 1.0);
}
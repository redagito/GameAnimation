#version 460 core

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

in vec3 vert_position;
in vec3 vert_normal;
in vec2 vert_uv;

out vec3 frag_normal;
out vec3 frag_position;
out vec2 frag_uv;

void main()
{
    frag_position = vec3(proj * view * model * vec4(position, 1.0));
    frag_normal = vec3(model * vec4(out_normal, 1.0));
    frag_uv = uv;
}
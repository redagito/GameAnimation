#version 460 core

// Single global directional light source
uniform vec3 light_direction;
uniform sampler2D base_texture;

in vec3 frag_position;
in vec3 frag_normal;
in vec2 frag_uv;

out vec4 frag_color;

void main()
{
    frag_normal = normalize(frag_normal);
    light_direction = normalize(light_direction);

    vec4 base_color = texture(base_texture, frag_uv);
    float intensity = clamp(dot(frag_normal, light_direction), 0.0, 1.0);

    frag_color = base_color * intensity;
}
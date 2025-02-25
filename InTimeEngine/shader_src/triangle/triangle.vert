#version 450

// in
layout(location = 0) in vec2 inPosition;
layout(location = 1) in vec3 inColor;

// out
layout(location = 0) out vec3 fragColor;

void main() {
    gl_Position = vec4(inPosition, 0.0, 1.0);
    fragColor = inColor;
}

//C7531: global variable gl_VertexIndex requires "#extension GL_KHR_vulkan_glsl : enable" before use
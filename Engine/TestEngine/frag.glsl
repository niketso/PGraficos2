#version 330 core

// Valores interpolados de los vertex shaders
in vec2 UV;

// Valores de salida
out vec3 color;

// Valores que permanecen constantes para toda la malla.
uniform sampler2D myTextureSampler;

void main()
{
    // Color de Salida = color de la textura en las coordenadas UV específicadas
    color = texture( myTextureSampler, UV ).rgb;
}
#ifndef MESH
#define MESH

#include <string>
#include <vector>
#include "../math/vec3.h"
#include "../math/vec2.h"
#include "../OpenGLWrappers/Shader.h"
#include "../OpenGLWrappers/Texture.h"

struct Vertex {
    vec3 Position;
    vec3 Normal;
    vec2 TexCoords;
    vec3 Tangent;
    vec3 Bitangent;
};

class Mesh {
public:
    Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
    void Draw(Shader& shader);

    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture> textures;

private:
    unsigned int VBO, EBO, VAO;
    void Setup();
};

#endif
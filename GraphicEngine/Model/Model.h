#ifndef MODEL
#define MODEL

#include <string>
#include <iostream>
#include <vector>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "../stb/stb_image.h"
#include "../Math/vec3.h"
#include "../Math/vec2.h"
#include "Mesh.h"
#include "../OpenGlWrappers/Shader.h"
#include "../OpenGlWrappers/Texture.h"

class Model
{
public:
    Model(std::string const& path);
    void Draw(Shader& shader);

    std::vector<Texture> textures_loaded;
    std::vector<Mesh> meshes;
    std::string directory;

private:
    void ProcessNode(aiNode* node, const aiScene* scene);
    Mesh ProcessMesh(aiMesh* mesh, const aiScene* scene);

    std::vector<Texture> LoadMaterial(aiMaterial* mat, aiTextureType type, std::string typeName);
};

#endif
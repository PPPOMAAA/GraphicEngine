#ifndef TEXTURE
#define TEXTURE

#include <iostream>
#include <vector>

#include <GL/glew.h>
#include "../stb/stb_image.h"

class Texture {
public:
	Texture(char const* path);
	Texture(const char* path, const std::string& directory);
	Texture(std::vector<std::string> pathes);
	void Bind(int flag = -1);

private:
	unsigned int id;
	std::string type;
	std::string path;
};

#endif
#ifndef TEXTURE
#define TEXTURE

#include <iostream>

#include <GL/glew.h>
#include "../stb/stb_image.h"

class Texture {
public:
	Texture(char const* path);
	void Bind(int flag = -1);

private:
	unsigned int id;
};

#endif
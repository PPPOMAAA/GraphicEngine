#ifndef SKYBOX
#define SKYBOX

#include "../OpenGLWrappers/Shader.h"
#include "Camera.h"
#include "../OpenGLWrappers/Vertex_array.h"
#include "../OpenGLWrappers/Vertex_buffer.h"

class Skybox {
public:
	void Setup(Shader& shader);
	void Draw(Shader& shader, Class_camera& camera);

private:
	Vertex_array VAO;
};

#endif
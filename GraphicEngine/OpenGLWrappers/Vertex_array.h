#ifndef ARRAY
#define ARRAY

#include <GL/glew.h>

class Vertex_array {
public:
	Vertex_array();
	void AttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer);
	void Bind(int flag = -1);
	void Delete();

private:
	unsigned int id;
};

#endif
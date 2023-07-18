#include "Vertex_array.h"

Vertex_array::Vertex_array() {
	glGenVertexArrays(1, &id);
	Bind();
}

void Vertex_array::AttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer) {
	glVertexAttribPointer(index, size, type, normalized, stride, pointer);
	glEnableVertexAttribArray(index);
}

void Vertex_array::Bind(int flag) {
	if (flag == 0)
		glBindVertexArray(0);
	else
		glBindVertexArray(id);
}

void Vertex_array::Delete() {
	glDeleteVertexArrays(1, &id);
}

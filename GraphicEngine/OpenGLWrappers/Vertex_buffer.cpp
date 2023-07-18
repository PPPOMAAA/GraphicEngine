#include "Vertex_buffer.h"

Vertex_buffer::Vertex_buffer(float data[], int size) {
	glGenBuffers(1, &id);
	Bind();
	glBufferData(GL_ARRAY_BUFFER, size * sizeof(data), data, GL_STATIC_DRAW);
}

void Vertex_buffer::Bind(int flag) {
	if (flag == 0)
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	else
		glBindBuffer(GL_ARRAY_BUFFER, id);
}

void Vertex_buffer::Delete() {
	glDeleteBuffers(1, &id);
}

#ifndef BUFFER
#define BUFFER

#include <GL/glew.h>

class Vertex_buffer {
public:
	Vertex_buffer(float data[], int size);
	void Bind(int flag = -1);
	void Delete();

private:
	unsigned int id;
};

#endif
#ifndef SHADER
#define SHADER

#include <GL/glew.h>
#include <string>

#include "../glm/vec2.hpp"
#include "../glm/vec3.hpp"
#include "../glm/vec4.hpp"
#include "../glm/mat4x4.hpp"

#include "../math/math4.h"
#include "../math/vec3.h"
#include "shaderLoader.h"

class Shader {
public:
	Shader(std::string first, std::string second) {
		id = LoadShaders(first, second);
	}
	void Use() {
		glUseProgram(id);
	}
	void SetMat4(std::string type,const math4& mat) {
		glm::mat4 res = Math4(mat);
		glUniformMatrix4fv(glGetUniformLocation(id, type.c_str()), 1, GL_FALSE, &res[0][0]);
	}
	void SetVec3(const std::string unif, const vec3& data) {
		glm::vec3 res = glm::vec3(data.x, data.y, data.z);
		glUniform3fv(glGetUniformLocation(id, unif.c_str()), 1, &res[0]);
	}
	void SetInt(const std::string unif, int data) {
		glUniform1i(glGetUniformLocation(id, unif.c_str()), data);
	}
	void SetFloat(const std::string unif, float data) {
		glUniform1f(glGetUniformLocation(id, unif.c_str()), data);
	}

private:
	unsigned int id;
	glm::mat4 Math4(const math4& mat) {
		return glm::mat4(mat.matrix[0][0], mat.matrix[0][1], mat.matrix[0][2], mat.matrix[0][3],
			mat.matrix[1][0], mat.matrix[1][1], mat.matrix[1][2], mat.matrix[1][3],
			mat.matrix[2][0], mat.matrix[2][1], mat.matrix[2][2], mat.matrix[2][3],
			mat.matrix[3][0], mat.matrix[3][1], mat.matrix[3][2], mat.matrix[3][3]);
	}
};

#endif
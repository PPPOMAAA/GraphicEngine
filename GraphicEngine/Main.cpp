#include <iostream>

//glew
#include <GL/glew.h>

//sfml
#include <SFML/Window.hpp>

using namespace std;

int main() {
	sf::ContextSettings settings;
	settings.depthBits = 24; // количество битов буффера глубины
	settings.stencilBits = 8; //количество битов буфера трафарета
	settings.majorVersion = 4;
	settings.minorVersion = 3;
	settings.attributeFlags = sf::ContextSettings::Core;

	sf::Window window(sf::VideoMode(800, 600, 32), "Engine",
		sf::Style::Titlebar | sf::Style::Close);

	glewExperimental = GL_TRUE; // включить все современные функции ogl

	if (GLEW_OK != glewInit()) { // включить glew
		cout << "Error:: glew not init =(" << endl;
		return -1;
	}

	const char* vshader = 
		"version 330 core\n"
		"layout (location = 0) in vec3 inPos;\n"
		"void main() {\n"
		"	gl_Position = vec4(inPos, 1.0);"
		"}\n";
	const char* fshader = 
		"version 330 core\n"
		"out vec4 OutColor;\n"
		"void main() {\n"
		"	OutColor = vec4(1.0, 0.0, 0.0, 1.0);"
		"}\n";

	int vshaderId = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vshaderId, 1, &vshader, nullptr);
	glCompileShader(vshaderId);

	int res = 0;
	glGetShaderiv(vshaderId, GL_COMPILE_STATUS, &res);
	/*if (!res) {
		char log[512];
		glGetShaderInfoLog(vshaderId, 512, nullptr, log);
		return 1;
	}*/

	int fshaderId = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fshaderId, 1, &fshader, nullptr);
	glCompileShader(fshaderId);

	glGetShaderiv(fshaderId, GL_COMPILE_STATUS, &res);
	/*if (!res) {
		char log[512];
		glGetShaderInfoLog(fshaderId, 512, nullptr, log);
		return 2;
	}*/

	int shaderId = glCreateProgram();
	glAttachShader(shaderId, vshaderId);
	glAttachShader(shaderId, fshaderId);
	glLinkProgram(shaderId);
	glGetShaderiv(shaderId, GL_LINK_STATUS, &res);
	/*if (!res) {
		char log[512];
		glGetShaderInfoLog(shaderId, 512, nullptr, log);
		return 3;
	}*/

	glDeleteShader(vshaderId);
	glDeleteShader(fshaderId);

	float verts[]{
		0.0f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f
	};

	unsigned indes[]{
		0, 1, 2
	};

	unsigned VAO = 0, VBA = 0, IBA = 0;
	glCreateVertexArrays(1, &VAO);
	glGenBuffers(1, &VBA);
	glGenBuffers(1, &IBA);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBA);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBA);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indes), indes, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);

	bool isGo = true;

	while (isGo) {
		sf::Event windowEvent;

		while (window.pollEvent(windowEvent)) { // обработка ивентов
			switch (windowEvent.type)
			{
			case sf::Event::Closed:
				isGo = false;
				break;
			default:
				break;
			}
		}

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f); //отчистка экрана
		glClear(GL_COLOR_BUFFER_BIT); //отчистка экрана

		glUseProgram(shaderId);
		glBindVertexArray(VAO);

		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

		glBindVertexArray(0);

		window.display();
	}


	window.close();
	return 0;
}

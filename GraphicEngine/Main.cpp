#pragma once

#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <GL/glew.h>
#include <SFML/Window.hpp>

#include "math/math4.h"
#include "math/vec3.h"

#include "Camera/Camera.h"
#include "Camera/Skybox.h"
#include "OpenGLWrappers/Texture.h"
#include "OpenGLWrappers/shaderLoader.h"
#include "stb/stb_image.h"
#include "OpenGLWrappers/Shader.h"
#include "OpenGLWrappers/Vertex_array.h"
#include "OpenGLWrappers/Vertex_buffer.h"

int height = 1600;
int width = 900;

vec3 ambient(0.2f, 0.2f, 0.2f);
vec3 diffuse(0.5f, 0.5f, 0.5f);
vec3 specular(1.0f, 1.0f, 1.0f);

float constant = 1.0f;
float linear = 0.09f;
float quadratic = 0.032f;
float shininess = 32.0f;

int main() {
	sf::ContextSettings settings;
	settings.depthBits = 24;
	settings.stencilBits = 8;
	settings.majorVersion = 4;
	settings.minorVersion = 3;
	settings.attributeFlags = sf::ContextSettings::Core;

	sf::Window window(sf::VideoMode(height, width, 24), "Graphic Engine",
		sf::Style::Titlebar | sf::Style::Close, settings);

	glewExperimental = GL_TRUE;
	glEnable(GL_DEPTH_TEST);

	if (GLEW_OK != glewInit()) {
		std::cout << "Error:: glew not init =(" << std::endl;
		return -1;
	}

	sf::Mouse::setPosition(sf::Vector2i(height / 2, width / 2), window);
	Class_camera camera;

	Shader cube("shaders/texture.vs", "shaders/texture.fs");
	Shader light("shaders/point.vs", "shaders/point.fs");
	Shader skybox_shader("shaders/skybox.vs", "shaders/skybox.fs");

	std::vector<std::string> faces{
		"textures/panorama_0.png",
		"textures/panorama_1.png",
		"textures/panorama_2.png",
		"textures/panorama_3.png",
		"textures/panorama_4.png",
		"textures/panorama_5.png"
	};

	Texture sky(faces);
	Skybox skybox;
	skybox.Setup(skybox_shader);

	float vertices[] = {
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 0.0f, 0.0f,
		0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
		0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
		0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
		0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

		0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
		0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
		0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
		0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
		0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f
	};

	Vertex_array cubeVAO;
	Vertex_buffer VBO(vertices, sizeof(vertices) / sizeof(float));
	cubeVAO.AttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	cubeVAO.AttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	cubeVAO.AttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	Vertex_array lightCubeVAO;
	VBO.Bind();
	cubeVAO.AttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);

	vec3 pos_light1(1.0f, 0.0f, 0.0f);
	vec3 pos_light2(-1.0f, 3.0f, 1.0f);

	vec3 pos_cube[] = {
		vec3(1.0f,  2.0f, 1.0f),
		vec3(-1.0f,  -2.0f, -1.0f),
		vec3(0.0f,  0.0f, -0.0f)
	};

	Texture cube_diff("textures/CAPYBARA.png");

	cube.Use();
	cube.SetInt("material.diffuse", 0);

	bool isGo = true;
	while (isGo) {
		sf::Event windowEvent;
		while (window.pollEvent(windowEvent)) {
			switch (windowEvent.type) {
			case sf::Event::Closed:
				isGo = false;
				break;
			case sf::Event::KeyPressed:
				camera.KeyboardInput();
				break;
			case sf::Event::MouseMoved:
				camera.MouseInput(window);
				break;
			default:
				break;
			}
		}

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		skybox.Draw(skybox_shader, camera);

		cube.Use();
		cube.SetVec3("viewPos", camera.GetPos());
		cube.SetFloat("material.shininess", shininess);

		cube.SetVec3("dirLight.direction", vec3(-0.2f, -1.0f, -0.3f));
		cube.SetVec3("dirLight.ambient", vec3(0.05f, 0.05f, 0.05f));
		cube.SetVec3("dirLight.diffuse", vec3(0.4f, 0.4f, 0.4f));
		cube.SetVec3("dirLight.specular", vec3(0.5f, 0.5f, 0.5f));

		cube.SetVec3("pointLights[0].position", pos_light1);
		cube.SetVec3("pointLights[0].ambient", vec3(0.05f, 0.05f, 0.05f));
		cube.SetVec3("pointLights[0].diffuse", vec3(0.3f, 0.3f, 0.3f));
		cube.SetVec3("pointLights[0].specular", specular);
		cube.SetFloat("pointLights[0].constant", constant);
		cube.SetFloat("pointLights[0].linear", linear);
		cube.SetFloat("pointLights[0].quadratic", quadratic);

		cube.SetVec3("pointLights[1].position", pos_light2);
		cube.SetVec3("pointLights[1].ambient", vec3(0.05f, 0.05f, 0.05f));
		cube.SetVec3("pointLights[1].diffuse", vec3(1.0f, 1.0f, 1.0f));
		cube.SetVec3("pointLights[1].specular", specular);
		cube.SetFloat("pointLights[1].constant", constant);
		cube.SetFloat("pointLights[1].linear", linear);
		cube.SetFloat("pointLights[1].quadratic", quadratic);

		cube.SetVec3("spotLight.position", camera.GetPos());
		cube.SetVec3("spotLight.direction", camera.GetFront());
		cube.SetVec3("spotLight.ambient", vec3(0.0f, 0.0f, 0.0f));
		cube.SetVec3("spotLight.diffuse", vec3(1.0f, 1.0f, 1.0f));
		cube.SetVec3("spotLight.specular", specular);
		cube.SetFloat("spotLight.constant", constant);
		cube.SetFloat("spotLight.linear", linear);
		cube.SetFloat("spotLight.quadratic", quadratic);
		cube.SetFloat("spotLight.cutOff", cos(12.5f * 180.0f / M_PI));
		cube.SetFloat("spotLight.outerCutOff", cos(15.0f * 180.0f / M_PI));

		math4 projection = camera.GetProjectionMatrix();
		math4 view = camera.GetViewMatrix();

		cube.SetMat4("projection", projection);
		cube.SetMat4("view", view);

		cube_diff.Bind(0);

		cubeVAO.Bind();
		for (int i = 0; i < 3; i++)
		{
			math4 model(1.0f);
			model = model.Translate(pos_cube[i]);
			float angle = 20.0f * i;
			cube.SetMat4("model", model);
			glDrawArrays(GL_TRIANGLES, 0, 36);
		}

		light.Use();
		light.SetMat4("projection", projection);
		light.SetMat4("view", view);

		math4 model1(1.0f);
		model1 = model1.Translate(pos_light1);
		model1 = model1.Scale(vec3(0.3f));
		light.SetMat4("model", model1);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		math4 model2(1.0f);
		model2 = model2.Translate(pos_light2);
		light.SetMat4("model", model2);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		lightCubeVAO.Bind();

		window.display();
	}

	VBO.Delete();
	cubeVAO.Delete();
	lightCubeVAO.Delete();

	window.close();
	return 0;
}
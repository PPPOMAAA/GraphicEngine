#include "Camera.h"

Class_camera::Class_camera() {
	cameraPos = vec3(0.0f, 0.0f, 3.0f);
	cameraFront = vec3(0.0f, 0.0f, -1.0f);
	cameraUp = vec3(0.0f, 1.0f, 0.0f);
	yaw = -90.0f;
	pitch = 0.0f;
	cameraSpeed = 0.1f;
}

math4 Class_camera::GetProjectionMatrix() {
	math4 projection;
	return projection.Perspective(45.0f * 180.0f / M_PI, 1600.0f / 900.0f, 0.1f, 100.0f);
}

math4 Class_camera::GetViewMatrix() {
	math4 view;
	return view.LookAt(cameraPos, cameraPos + cameraFront, cameraUp);
}

void Class_camera::KeyboardInput() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		cameraPos += cameraFront * cameraSpeed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		cameraPos -= cameraFront * cameraSpeed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		vec3 result = cameraFront.VectorMultiplication(cameraUp);
		cameraPos -= result.Normalize() * cameraSpeed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		vec3 result = cameraFront.VectorMultiplication(cameraUp);
		cameraPos += result.Normalize() * cameraSpeed;
	}
}

void Class_camera::MouseInput(sf::Window& window) {
	if (firstMouse)
	{
		lastX = sf::Mouse::getPosition(window).x;
		lastY = sf::Mouse::getPosition(window).y;
		firstMouse = false;
	}

	float xoffset = sf::Mouse::getPosition(window).x - lastX;
	float yoffset = lastY - sf::Mouse::getPosition(window).y;
	lastX = sf::Mouse::getPosition(window).x;
	lastY = sf::Mouse::getPosition(window).y;

	yaw += (xoffset * 0.0001f);
	pitch += (yoffset * 0.0001f);

	vec3 direction;
	direction.x = cos(yaw * 180.0f / M_PI) * cos(pitch * 180.0f / M_PI);
	direction.y = sin(pitch * 180.0f / M_PI);
	direction.z = sin(yaw * 180.0f / M_PI) * cos(pitch * 180.0f / M_PI);
	cameraFront = direction.Normalize();
}

vec3 Class_camera::GetPos() {
	return cameraPos;
}

vec3 Class_camera::GetFront() {
	return cameraFront;
}

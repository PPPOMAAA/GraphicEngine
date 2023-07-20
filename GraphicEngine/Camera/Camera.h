#ifndef CAMERA
#define CAMERA

#define _USE_MATH_DEFINES // for C++
#include <cmath>

#include "../math/math4.h"
#include "../math/vec3.h"

#include <SFML/Window.hpp>

class Class_camera {
public:
	Class_camera();
	math4 GetProjectionMatrix();
	math4 GetViewMatrix();
	math4 GetRightView();
	void KeyboardInput();
	void MouseInput(sf::Window&);
	vec3 GetPos();
	vec3 GetFront();

private:
	vec3 cameraPos;
	vec3 cameraFront;
	vec3 cameraUp;

	float yaw;
	float pitch;
	float cameraSpeed;

	bool firstMouse = true;

	float lastX = 1600 / 2.0f;
	float lastY = 600 / 2.0f;
};

#endif
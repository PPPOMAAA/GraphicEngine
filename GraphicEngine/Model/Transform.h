#pragma once

#define _USE_MATH_DEFINES
#include <cmath>
#include "../Math/math4.h"
#include "../Math/vec3.h"

class Transform {
public:
	void SetPosition(math4& object, vec3& newPosition);
	void Rotate(math4& object, float angle, vec3& vec);
	void Scale(math4& object, float size);
};

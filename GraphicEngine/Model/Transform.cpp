#include "Transform.h"

void Transform::SetPosition(math4& object, vec3& newPosition) {
	object.Translate(newPosition);
}

void Transform::Rotate(math4& object, float angle, vec3& vec) {
	object.Rotate(angle * 180.0f / M_PI, vec);
}

void Transform::Scale(math4& object, float size) {
	object.Scale(vec3(size));
}

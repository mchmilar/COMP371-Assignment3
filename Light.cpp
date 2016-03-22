#include "Light.h"
#include <stdexcept>



void Light::setColour(vec3 colour) {
	if (isValidColour(colour)) {
		this->colour = colour;
	}
	else {
		throw std::invalid_argument("Colour must be between [0,1]");
	}
}

// Makes sure colour components are within [0,1]
bool Light::isValidColour(vec3 colour)
{
	return colour.x <= 1.0f && colour.x >= 0
		&& colour.y <= 1.0f && colour.x >= 0
		&& colour.z <= 1.0f && colour.z >= 0;
}

float Light::intersects(Ray ray) {
	return 0;
}
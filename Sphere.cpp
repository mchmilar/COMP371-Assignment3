#include "Sphere.h"
#include <stdexcept>


// Setters

void Sphere::setRadius(float radius)
{
	if (radius <= 0.0f) {
		throw std::invalid_argument("Radius must be greater than zero");
	}
	
	this->radius = radius;
}

void Sphere::setPosition(vec3 position)
{
	this->getPosition = position;
}


// Getters

float Sphere::getRadius()
{
	return radius;
}


vec3 Sphere::getPosition()
{
	return position;
}

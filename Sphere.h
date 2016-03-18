#pragma once
#include "glm.hpp"
#include "SimpleShape.h"

using namespace glm;

class Sphere : public SimpleShape
{
public:
	Sphere() {};
	~Sphere() {};
protected:
	float radius;
public:

	Sphere(vec3 position, float radius, vec3 ambientColour, vec3 diffuseColour, vec3 specularColour, float shininess) :
		SimpleShape(ambientColour, diffuseColour, specularColour, shininess)
	{
		setRadius(radius);
		setPosition(position);
	}

	// Setters
	void setRadius(float radius);
	void setPosition(vec3 position);

	// Getters
	float getRadius();
	vec3 getPosition();
};


#pragma once
#include "SimpleShape.h"
class Plane :
	public SimpleShape
{
public:
	// Constructors
	Plane(vec3 normal, vec3 position, vec3 ambientColour, vec3 diffuseColour, vec3 specularColour, float shininess)
		: SimpleShape(position, ambientColour, diffuseColour, specularColour, shininess)
		, normal(normal) {}

	Plane() {};
	~Plane() {};

	// Setters
	void setNormal(vec3 normal) { this->normal = normal; }

	// Getters
	vec3 getNormal() { return normal; }

protected:
	vec3 normal;

	
};


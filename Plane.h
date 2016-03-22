#pragma once
#include "SimpleShape.h"
#include "Ray.h"


class Plane :
	public SimpleShape
{
public:
	// Constructors
	Plane(vec3 normal, vec3 position, vec3 ambientColour, vec3 diffuseColour, vec3 specularColour, float shininess)
		: SimpleShape(position, ambientColour, diffuseColour, specularColour, shininess)
		, normal(normalize(normal)) {}

	Plane(vec3 normal, vec3 position)
		: Plane(normal, position, vec3(), vec3(), vec3(), 0.0f) {}

	Plane() {};
	~Plane() {};

	float intersects(Ray ray);
	vec3 Plane::reflectedDiffuseColour(vec3 q, Light light);
	vec3 Plane::reflectedSpecularColour(vec3 q, Light light);
	// Setters
	void setNormal(vec3 normal) { this->normal = normalize(normal); }

	// Getters
	vec3 getNormal() { return normal; }

protected:
	vec3 normal;

	
};


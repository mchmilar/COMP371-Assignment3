#pragma once
#include "SimpleShape.h"
#include <iostream>
#include "string_cast.hpp"
#include "Ray.h"
using namespace glm;

class Ray;
class Sphere : public SimpleShape
{
private:
	float radius;

public:

	Sphere(vec3 position, float radius, vec3 ambientColour, vec3 diffuseColour, vec3 specularColour, float shininess) :
		SimpleShape(position, ambientColour, diffuseColour, specularColour, shininess)
	{
		setRadius(radius);
	}

	Sphere() {};
	~Sphere() {};

	
	float intersects(Ray ray);
	
	vec3 Sphere::reflectedDiffuseColour(vec3 q, Light light);
	vec3 Sphere::reflectedSpecularColour(vec3 q, Light light);

	// Setters
	void setRadius(float radius);

	// Getters
	float getRadius() { return radius; }

	// Operator overloading
	friend std::ostream& operator <<(std::ostream& outputStream, Sphere& sphere);
};

//const std::ostream& operator <<(std::ostream& outputStream, vec3 vector) {
//	outputStream << vector.x << " " << vector.y << " " << vector.z << std::endl;
//	return outputStream;
//}

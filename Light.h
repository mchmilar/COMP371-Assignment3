#pragma once
#include "Object.h"
#include "Ray.h"
#include "glm.hpp"

using namespace glm;

class Light :
	public Object
{
public:

	// Constructors
	Light() {};
	~Light() {};
	Light(vec3 position, vec3 colour) {
		setPosition(position);
		setColour(colour);
	}

	float intersects(Ray ray);

	// Setters
	void setPosition(vec3 position) { this->position = position; }
	void setColour(vec3 colour);

	// Getters
	vec3 getPosition() { return position; }
	vec3 getColour() { return colour; }
	
private:
	bool isValidColour(vec3 colour);
protected:
	vec3 colour;
};


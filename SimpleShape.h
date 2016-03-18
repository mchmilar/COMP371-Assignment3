#pragma once
#include "glm.hpp"
#include "Object.h"

using namespace glm;

class SimpleShape : public Object
{
public:
	//Constructors
	SimpleShape(vec3 position, vec3 aColour, vec3 dColour, vec3 sColour, float shine);
	SimpleShape() {};
	~SimpleShape() {};

	// Setters
	void setAmbientColour(vec3 ambientColour);
	void setDiffuseColour(vec3 diffuseColour);
	void setSpecularColour(vec3 specularColour);
	void setShininess(float shininess);
	void setPosition(vec3 position) { this->position = position; }

	// Getters
	vec3 getAmbientColour();
	vec3 getDiffuseColour();
	vec3 getSpecularColour();
	float getShininess();
	vec3 getPosition() { return position; }

protected:
	// SimpleShape properties
	vec3 ambientColour;
	vec3 diffuseColour;
	vec3 specularColour;
	float shininess;

private:
	
	bool isValidColour(vec3 colour);
};


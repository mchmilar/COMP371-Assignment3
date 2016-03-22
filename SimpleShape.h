#pragma once
#include "glm.hpp"
#include "Object.h"
#include "Light.h"

using namespace glm;

const static float Kd = 0.5f;
class SimpleShape : public Object
{
public:
	//Constructors
	SimpleShape(vec3 position, vec3 aColour, vec3 dColour, vec3 sColour, float shine);
	SimpleShape(vec3 aColour, vec3 dColour, vec3 sColour, float shine)
		: SimpleShape(vec3(0.0f), aColour, dColour, sColour, shine) {}
	SimpleShape() {};
	~SimpleShape() {};

	virtual vec3 reflectedDiffuseColour(vec3 q, Light light) = 0;
	virtual vec3 reflectedSpecularColour(vec3 q, Light light) = 0;

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

	
	

private:
	// SimpleShape properties
	vec3 ambientColour;
	vec3 diffuseColour;
	vec3 specularColour;
	float shininess;

	bool isValidColour(vec3 colour);
};


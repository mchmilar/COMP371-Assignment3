#include "SimpleShape.h"
#include <stdexcept>

SimpleShape::SimpleShape(vec3 position, vec3 aColour, vec3 dColour, vec3 sColour, float shine)
{
	setPosition(position);
	setAmbientColour(aColour);
	setDiffuseColour(dColour);
	setSpecularColour(sColour);
	setShininess(shine);
}



// Sets the ambient colour of the SimpleShape
void SimpleShape::setAmbientColour(vec3 ambientColour)
{
	if (isValidColour(ambientColour)) {
		this->ambientColour = ambientColour;
	}
	else {
		throw std::invalid_argument("Ambient Colour values must be between 0 and 1");
	}
}


// Sets the diffuse color
void SimpleShape::setDiffuseColour(vec3 diffuseColour)
{
	if (isValidColour(diffuseColour)) {
		this->diffuseColour = diffuseColour;
	}
	else {
		throw std::invalid_argument("Diffuse Colour values must be between 0 and 1");
	}
}


// Sets the specular colour of the SimpleShape
void SimpleShape::setSpecularColour(vec3 specularColour)
{
	if (isValidColour(specularColour)) {
		this->specularColour = specularColour;
	}
	else {
		throw std::invalid_argument("Specular Colour values must be btween 0 and 1");
	}
}


// Sets the specular shininess of the SimpleShape
void SimpleShape::setShininess(float shininess)
{
	if (shininess >= 0 && shininess <= 1) {
		this->shininess = shininess;
	}
	else {
		throw std::invalid_argument("Shininess must be between 0 and 1");
	}
}


// Get the SimpleShapes ambient colour
vec3 SimpleShape::getAmbientColour()
{
	return ambientColour;
}


// Get the SimpleShapes diffuse colour
vec3 SimpleShape::getDiffuseColour()
{
	return diffuseColour;
}


// Get the SimpleShapes specular colour
vec3 SimpleShape::getSpecularColour()
{
	return specularColour;
}


// Get the SimpleShapes specular shininess
float SimpleShape::getShininess()
{
	return shininess;
}



// Makes sure colour components are within [0,1]
bool SimpleShape::isValidColour(vec3 colour)
{
	return colour.x <= 1.0f && colour.x >= 0
		&& colour.y <= 1.0f && colour.x >= 0
		&& colour.z <= 1.0f && colour.z >= 0;
}

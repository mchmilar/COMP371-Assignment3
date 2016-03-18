#pragma once
#include "SimpleShape.h"
class Plane :
	public SimpleShape
{
public:
	Plane() {};
	~Plane() {};
protected:
	vec3 normal;
public:
	Plane(vec3 normal, vec3 position, vec3 ambientColour, vec3 diffuseColour, vec3 specularColour, float shininess)
		: SimpleShape(;
};


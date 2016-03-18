#pragma once
#include "SimpleShape.h"
class Triangle :
	public SimpleShape
{
public:

	// Constructors
	Triangle() {};
	~Triangle() {};

	Triangle(vec3 vertex1, vec3 vertex2, vec3 vertex3, vec3 ambientColour, vec3 diffuseColour, vec3 specularColour, float shininess)
		: SimpleShape(vec3(vertex1, vertex2, vertex3), ambientColour, diffuseColour, specularColour, shininess) {}
	
	// Setters
	void setPosition(vec3 vertex1, vec3 vertex2, vec3 vertex3)
	{
		SimpleShape::setPosition(vec3(vertex1, vertex2, vertex3));
	}

	
};


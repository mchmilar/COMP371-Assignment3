#pragma once
#include "SimpleShape.h"
class Triangle :
	public SimpleShape
{
public:
	Triangle();
	~Triangle();

	Triangle(vec3 vertex1, vec3 vertex2, vec3 vertex3, vec3 ambientColour, vec3 diffuseColour, vec3 specularColour, float shininess)
		: SimpleShape(ambientColour, diffuseColour, specularColour, shininess)
	{
		setPosition(vertex1, vertex2, vertex2);
	}
	void setPosition(vec3 position);
	void setPosition(vec3 vertex1, vec3 vertex2, vec3 vertex3);
	vec3 getPosition();
};


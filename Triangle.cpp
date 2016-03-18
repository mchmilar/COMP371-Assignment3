#include "Triangle.h"



Triangle::Triangle()
{
}


Triangle::~Triangle()
{
}


void Triangle::setPosition(vec3 position)
{
	this->position = position;
}

void Triangle::setPosition(vec3 vertex1, vec3 vertex2, vec3 vertex3) {
	setPosition(vec3(vertex1, vertex2, vertex3));
}

vec3 Triangle::getPosition()
{
	return vec3();
}

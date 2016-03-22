#pragma once
#include "glm.hpp"

class Ray;
using namespace glm;
class Object
{
public:
	Object() {};
	~Object() {};
protected:
	vec3 position;
public:
	virtual vec3 getPosition() = 0;
	virtual void setPosition(vec3) = 0;
	virtual float intersects(Ray) = 0;
	
};


#pragma once
#include "glm.hpp"

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
	virtual void setPosition() = 0;
};


#pragma once
#include "glm.hpp"

using namespace glm;


class Ray
{
private:
	vec3 origin;
	vec3 direction;
public:
	Ray(vec3 origin, vec3 direction) : origin(origin) {
		setDirection(normalize(direction));
	}
	Ray() {}
	~Ray() {}


	//float intersects(Sphere sphere);
//	float intersects(Triangle triangle);
//	float intersects(Plane plane);
//	float intersects(SimpleShape* shape);

	void setOrigin(vec3 origin)	{
		this->origin = origin;
	}

	void setDirection(vec3 direction) {
		this->direction = normalize(direction);
	}

	vec3 getOrigin() {
		return origin;
	}

	vec3 getDirection() {
		return direction;
	}




};


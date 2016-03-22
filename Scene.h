#pragma once
#include <vector>
#include "SimpleShape.h"
#include "Light.h"
#include "Ray.h"
#include "glm.hpp"

using namespace glm;

class Scene
{
public:
	const vec3 GLOBAL_AMBIENT = vec3(.1, .1, .1);
	const vec3 bg_colour = vec3(0);

	Scene() { objects = std::vector<SimpleShape*>(); lights = std::vector<Light>{}; }
	~Scene() {}

	std::vector<SimpleShape*> objects;
	std::vector<Light> lights;
	int d_max = 5;

	vec3 trace(Ray& ray, int d);
	SimpleShape* intersect(Ray& ray, vec3& q);
	vec3 acquireColour(vec3 q, SimpleShape* shape);
	void addObject(SimpleShape* shape);
	void addLight(Light light) { lights.push_back(light); }
};


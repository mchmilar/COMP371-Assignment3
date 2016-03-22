#include "Scene.h"
#include <iostream>

// Trace algorithm, returns pixel colour as a vector
vec3 Scene::trace(Ray& ray, int d)
{
	// Return background colour if we've recurred d_max times
	if (d > d_max)
		return bg_colour;

	

	vec3 q = vec3(0);
	SimpleShape* intersectingObject = intersect(ray, q); // q: object surface point
	if (intersectingObject == nullptr) // no intersection, return background colour
		return bg_colour; 

	


	vec3 colour = acquireColour(q, intersectingObject);

	return colour;
}

// Returns the surface point of the closest intersection
SimpleShape* Scene::intersect(Ray& ray, vec3& q) {
	
	float t = -1;
	SimpleShape* intersectingObject = nullptr;

	// Iterate through every object in objects vector
	for (auto object : objects) {
		
		float t_temp = object->intersects(ray);

		if (t < 0 && t_temp > 0) {
			t = t_temp;
			intersectingObject = object;
		}			
		else if (t > 0 && t_temp > 0 && t_temp < t) {
			t = t_temp;
			intersectingObject = object;
		}
			
	}
	if (t > 0) {
		q = ray.getOrigin() + t * ray.getDirection();
		
	}
			
	return intersectingObject;
}

vec3 Scene::acquireColour(vec3 q, SimpleShape* shape) {
	
	

	vec3 colour = shape->getAmbientColour();
//	colour += vec3(GLOBAL_AMBIENT.r * colour.r, GLOBAL_AMBIENT.g * colour.g, GLOBAL_AMBIENT.b * colour.b);
//	std::cout << colour.r << std::endl;
	for (Light light : lights) {
		float epsilon = 0.001;
		vec3 rayDirection = light.getPosition() - q;
		vec3 surfacePoint = q + rayDirection * epsilon;
		Ray ray = Ray(surfacePoint, rayDirection);

		if (intersect(ray, vec3(0)) == nullptr) {
			colour += shape->reflectedDiffuseColour(q, light);
		//	colour += shape->reflectedSpecularColour(q, light);
		}
	}
	
	if (colour.r > 1.0) colour.r = 1.0;
	if (colour.r < 0.0) colour.r = 0.0;

	if (colour.g > 1.0) colour.g = 1.0;
	if (colour.g < 0.0) colour.g = 0.0;

	if (colour.b > 1.0) colour.b = 1.0;
	if (colour.b < 0.0) colour.b = 0.0;
	return colour;
}

void Scene::addObject(SimpleShape* shape) {
	objects.push_back(shape);
}



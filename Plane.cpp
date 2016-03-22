#include "Plane.h"
#include <iostream>

// Returns the intersection point t of the plane and the ray
// Returns -1.0 if the ray and plane are parallel
float Plane::intersects(Ray ray) {

	// -t = (P_o * n + d) / (direction * n)
	/*std::cout << normal.y << std::endl;
	std::cout << ray.getDirection().x << std::endl;
	std::cout << ray.getOrigin().z << std::endl;
	std::cout << position.x << std::endl << std::endl;*/

	float normalDotDirection = dot(normal, ray.getDirection());
	float normalDotOrigin = dot(normal, ray.getOrigin());
	float d = -(dot(position, normal));
	
	if (normalDotDirection == 0.0f) {
		return -1.0f;
	}
	else {
		
		return -((normalDotOrigin + d) / normalDotDirection);
	}
}


vec3 Plane::reflectedDiffuseColour(vec3 q, Light light) {
	vec3 l = light.getPosition() - q;
	//float red, green, blue;
	float l_n = max(dot(l, normalize(normal)), 0.0f);
	float d = length(l);

	float attenuationDenom = 1 + .2 * d + pow(d, 2);
	float attenuation = 1 / attenuationDenom;

	vec3 surfaceDiffuseC = getDiffuseColour();
	/*red = Kd * dot(l, normal) * light.getColour().r;
	green = Kd * dot(l, normal) * light.getColour().g;
	blue = Kd * dot(l, normal) * light.getColour().b;*/
	vec3 colour = (light.getColour() + surfaceDiffuseC) * l_n * attenuation;
	return colour;
	//return vec3(red, green, blue);
}

vec3 Plane::reflectedSpecularColour(vec3 q, Light light) {
	return vec3(0);
}
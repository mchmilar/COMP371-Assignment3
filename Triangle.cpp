#include "Triangle.h"

void Triangle::calculatePlane() {
	vec3 A = vertices.at(2) - vertices.at(0);
	vec3 B = vertices.at(1) - vertices.at(0);
	vec3 n = normalize(cross(A, B));
	plane = Plane(n, vertices.at(0));
}


float Triangle::areaXYProjection(vec3 a, vec3 b, vec3 c) {
	return ((b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y)) * 0.5f;
}

float Triangle::barycentric(vec3 a, vec3 b, vec3 c) {
	return areaXYProjection(a, b, c) / XYarea;
}

vec3 Triangle::reflectedDiffuseColour(vec3 q, Light light) {
	vec3 l = light.getPosition() - q;
	
	float l_n = max(dot(l, normalize(plane.getNormal())), 0.0f);
	float d = length(l);

	float attenuationDenom = 1 + .2 * d + pow(d, 2);
	float attenuation = 1 / attenuationDenom;

	vec3 surfaceDiffuseC = getDiffuseColour();
	
	vec3 colour = (light.getColour() + surfaceDiffuseC) * l_n * attenuation;
	return colour;
	
}

vec3 Triangle::reflectedSpecularColour(vec3 q, Light light) {
	return vec3(0);
}
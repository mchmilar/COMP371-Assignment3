#include "Sphere.h"
#include <stdexcept>


// Setters

void Sphere::setRadius(float radius)
{
	if (radius <= 0.0f) {
		throw std::invalid_argument("Radius must be greater than zero");
	}
	
	this->radius = radius;
}




// Output overload
std::ostream& operator <<(std::ostream& outputStream, Sphere& sphere) {
	outputStream << "Position = " << to_string(sphere.getPosition()) << std::endl;
	outputStream << "Radius = " << sphere.getRadius() << std::endl;
	outputStream << "Ambient Colour = " << to_string(sphere.getAmbientColour()) << std::endl;
	outputStream << "Diffuse Colour = " << to_string(sphere.getDiffuseColour()) << std::endl;
	outputStream << "Specular Colour = " << to_string(sphere.getSpecularColour()) << std::endl;
	outputStream << "Shininess = " << sphere.getShininess() << std::endl;
	return outputStream;
}


// Returns the t parameter of the intersection point
// Returns 0 (false) if there's no intersection
float Sphere::intersects(Ray ray) {

	// Ray info
	vec3 direction = ray.getDirection();
	vec3 origin = ray.getOrigin();

	vec3 centre = position;
	float r = radius;
	float b = 2 * dot(direction, origin - centre);
	float c = dot(origin - centre, origin - centre) - (r * r);
	float discriminant = (b * b) - 4 * c;
	if (discriminant < 0) {
		return 0; // false
	}
	else if (discriminant == 0.0f) {
		return -b / 2;
	}
	else {
		float t1 = (-b + sqrt(discriminant)) / 2;
		float t2 = (-b - sqrt(discriminant)) / 2;
		if (t1 < 0) return t2;
		if (t2 < 0) return t1;

		return min(t1, t2);
	}

	return 0.0f;
}

vec3 Sphere::reflectedDiffuseColour(vec3 q, Light light) {
	vec3 n = normalize(q - position);
	vec3 l = light.getPosition() - q;
	float red, green, blue;
	float l_n = max(dot(l, n), 0.0f);
	//std::cout << l_n << std::endl;
	float d = length(l);

	//float attenuationDenom = 3 + 6 * d + pow(d, 2);
	float attenuation = 1 / pow( (d/radius + 1), 2);

	vec3 surfaceDiffuseC = getDiffuseColour();

	red = attenuation * Kd * l_n * (light.getColour().r + surfaceDiffuseC.r);
	green = attenuation * Kd * l_n * (light.getColour().g + surfaceDiffuseC.g);
	blue = attenuation * Kd * l_n * (light.getColour().b + surfaceDiffuseC.b);

	vec3 colour = (light.getColour() + surfaceDiffuseC) * l_n * attenuation;
	
	return colour;
	//return vec3(red, green, blue);
}

vec3 Sphere::reflectedSpecularColour(vec3 q, Light light) {
	vec3 n = normalize(q - position);
	vec3 l = light.getPosition() - q;
	vec3 lNormalized = normalize(l);

	vec3 r = 2 * dot(lNormalized, n) * n - lNormalized;

	vec3 colour = 0.5 * ()
}
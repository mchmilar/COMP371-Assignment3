#pragma once
#include "Ray.h"
#include "glm.hpp"

#define M_PI        3.14159265358979323846264338327950288   /* pi */
#define DEG_TO_RAD  M_PI/180.0f
class Ray;
class Camera
{
public:
	Camera() {};
	Camera(glm::vec3 position, float fov, float focal_length, float aspect_ratio)
		: position(position),
		fov(DEG_TO_RAD * fov),
		focal_length(focal_length),
		aspect_ratio(aspect_ratio) {
		calculateDimensions();
		fov_x = 2 * atan((width / 2) / focal_length);
	};
	~Camera() {};

	float height, width, focal_length, fov_x;
	
	Ray pixelCoordinate(int i, int j);
	void calculateDimensions();
private:
	float fov;
	float aspect_ratio;
	glm::vec3 position;
};


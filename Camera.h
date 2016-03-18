#pragma once

#include "glm.hpp"

class Camera
{
public:
	Camera();
	Camera(glm::vec3 position, float fov, float focal_length, float aspect_ratio)
		: position(position),
		fov(fov),
		focal_length(focal_length),
		aspect_ratio(aspect_ratio) {};
	~Camera();
private:
	float fov;
	float focal_length;
	float aspect_ratio;
	glm::vec3 position;
};


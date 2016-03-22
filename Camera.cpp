#include "Camera.h"

void Camera::calculateDimensions() {
	height = 2 * focal_length * tan(fov * 0.5f);
	width = aspect_ratio * height;
}

// Calculate world coordinate for the pixel
// x and y are ints from 0->width and 0->height
Ray Camera::pixelCoordinate(int j, int i) {
	float xTheta = fov_x / 2;
	float yTheta = fov / 2;
	float halfWidth = width / 2;
	float halfHeight = height / 2;

	float alpha = focal_length * tan(xTheta) * ((j - halfWidth) / halfWidth);
	float beta = focal_length * tan(yTheta) * ((halfHeight - i) / halfHeight);
	//std::cout << std::endl << alpha << std::endl << beta << std::endl;
	return Ray(position, vec3(alpha, beta, -focal_length));
}
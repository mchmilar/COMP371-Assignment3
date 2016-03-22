#include "Camera.h"
#include "Sphere.h"
#include "Ray.h"
#include "Triangle.h"
#include "Scene.h"
#include "../cimg/Cimg.h"
#include "glm.hpp"

#include <array>
using namespace cimg_library;

class Ray;
int main() {
	try {
		vec3 zero = vec3(0.0f, 0.0f, 0.0f);
	
		Scene scene = Scene();
		
	
		Camera cam = Camera(vec3(0.0f, 2.0f, 10.0f), 60, 1000, 1.33);
	
		Sphere* sphere1 = new Sphere(vec3(0, 2, -10), 2, 
			vec3(0.5, 0.2, 0.7), 
			vec3(0.2, 0.4, 0.2), 
			vec3(0.1, 0.7, 0.2), 
			0.8);

		Sphere* sphere2 = new Sphere(vec3(0, 30, -50), 3,
			vec3(0.1, 0.5, 0.5),
			vec3(0.4, 0.6, 0.2),
			vec3(0.2, 0.5, 0.5),
			1.0);

		Plane* plane = new Plane(vec3(0, 1, 0), zero,
			vec3(.3, .5, .2),
			vec3(.5, .6, .2),
			vec3(.7, .5, .2),
			5);

		Triangle triangle = Triangle(vec3(0.0f, 100.0f, -100.0f), vec3(100.0f, -100.0f, -100.0f),
			vec3(-100.0f, -100.0f, -100.0f), zero, zero, zero, 0.0f);


		Light light = Light(vec3(0, 20, -10), vec3(0.7, 0.2, 0.3));
		scene.addLight(light);
		
		CImg<float> image(cam.width, cam.height, 1, 3, 0);

		Ray ray;

		std::cout << cam.width << std::endl << cam.height << std::endl;

		scene.addObject(sphere1);
		scene.addObject(sphere2);
		scene.addObject(plane);

		
		cimg_forXY(image, x, y) {
			ray = cam.pixelCoordinate(x, y);
			vec3 colour = scene.trace(ray, 0);
		//	std::cout << colour.r * 255 << std::endl;
			image(x, y, 0) = colour.r * 255;
			image(x, y, 1) = colour.g * 255;
			image(x, y, 2) = colour.b * 255;
						
		}

		image.save("render.bmp");

		CImgDisplay main_disp(image, "Render");
		while (!main_disp.is_closed())
			main_disp.wait();
	
	}
	catch (std::invalid_argument& e) {
		std::cerr << e.what() ;
	}
	return 0;
}





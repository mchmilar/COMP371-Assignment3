#include "Ray.h"

// Returns the t parameter of the intersection point
// Returns 0 (false) if there's no intersection
//float Ray::intersects(Sphere sphere) {
//	vec3 centre = sphere.getPosition();
//	float r = sphere.getRadius();
//	float b = 2 * dot(direction, origin - centre);
//	float c = dot(origin - centre, origin - centre) - (r * r);
//	float discriminant = (b * b) - 4 * c;
//	if (discriminant < 0) {
//		return 0; // false
//	}
//	else if (discriminant == 0.0f) {
//		return -b / 2;
//	}
//	else {
//		float t1 = (-b + sqrt(discriminant)) / 2;
//		float t2 = (-b - sqrt(discriminant)) / 2;
//		if (t1 < 0) return t2;
//		if (t2 < 0) return t1;
//
//		return min(t1, t2);
//	}
//
//	return 0.0f;
//}

//float Ray::intersects(Triangle triangle) {
//	float t = intersects(triangle.plane);
//	if (t >= 0) {
//		std::vector<vec3> vertices = triangle.getVertices();
//		vec3 p = origin + t * direction;
//		
//		float alpha = triangle.barycentric(p, vertices[1], vertices[2]);
//		float beta = triangle.barycentric(vertices[0], p, vertices[2]);
//		float gamma = triangle.barycentric(vertices[0], vertices[1], p);
//		float abc = alpha + beta + gamma;
//		
//		if (0 <= alpha && alpha <= 1 &&
//			0 <= beta && beta <= 1 &&
//			0 <= gamma && gamma <= 1 &&
//			abc == 1.0f) {
//			return t;
//		}
//		else return 0;
//	}
//	else {
//		return 0;
//	}
//
//
//}

//float Ray::intersects(SimpleShape* shape) {
//	intersects(shape);
//}



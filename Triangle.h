#pragma once
#include "SimpleShape.h"
#include "Plane.h"
#include <vector>


class Triangle :
	public SimpleShape
{
public:

	Plane plane = Plane();
	float XYarea;

	// Constructors
	Triangle() {};
	~Triangle() {};

	Triangle(vec3 vertex1, vec3 vertex2, vec3 vertex3, vec3 ambientColour, vec3 diffuseColour, vec3 specularColour, float shininess)
		: SimpleShape(ambientColour, diffuseColour, specularColour, shininess) {
		setVertices(vertex1, vertex2, vertex3);
		calculatePlane();
		XYarea = areaXYProjection(vertex1, vertex2, vertex3);
	}

	vec3 reflectedDiffuseColour(vec3 q, Light light);
	vec3 reflectedSpecularColour(vec3 q, Light light);
	void calculatePlane();
	float areaXYProjection(vec3 a, vec3 b, vec3 c);
	float barycentric(vec3 p1, vec3 p2, vec3 p3);
	float intersects(Ray) { return 0; }

	// Setters
	void setVertices(vec3 vertex1, vec3 vertex2, vec3 vertex3)	{
		vertices.push_back(vertex1);
		vertices.push_back(vertex2);
		vertices.push_back(vertex3);
	}

	// Getters
	std::vector<vec3> getVertices() { return vertices; }

private:
	std::vector<vec3> vertices = std::vector<vec3>();
	
};


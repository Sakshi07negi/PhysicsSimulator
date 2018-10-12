#pragma once
#include "Core.h"
#include <cmath>

struct Vector {
	int x = 0;
	int y = 0;

	void Sub(Vector vector);
	void Add(Vector vector);
	void Limit(int limit);
	void SetMag(float magnitude);
};

class PhysicsObject {
public:
	Vector position;
	int radius;
	int mass;
	SDL_Color color;
	Vector acceleration;
	Vector velocity;
public:
	PhysicsObject* next = nullptr;
public:
	PhysicsObject(SDL_Point* position, int radius, int mass, SDL_Color* color);
	void DrawCircle();
};

class PhysicsEngine {
private:
	// Linked list
	PhysicsObject* firstObject = nullptr;
	PhysicsObject* lastObject = nullptr;

	int mouseMass = 6.698*pow(10, 27);
	Vector* mouse = nullptr;
	Vector* acceleration = nullptr;
	Vector* velocity = nullptr;
public:
	PhysicsEngine(); 
	~PhysicsEngine();

	void UpdatePhysics();
	void AddToQueue(PhysicsObject* object);
	/**
	@Desciption: Inserts a sphere into the space
	@Return type: PhysicsObject*
	*/
	PhysicsObject* SummonObject(SDL_Point* position, int radius, int mass, SDL_Color* color);
};


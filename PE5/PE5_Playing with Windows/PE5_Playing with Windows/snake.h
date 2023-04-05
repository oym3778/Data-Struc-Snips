#pragma once
#include "Box2D/Box2D.h"
using namespace sf; 

/// <summary>/// updates the physics world using DeltaTime /// </summary>
void update(b2World* world, Clock* deltaClock);

/// <summary>/// displays the position of the target and the player. /// </summary>
void display(b2Body* snake, b2Body* target);

/// <summary> /// reads the key presses and applies the forces to the player to move /// </summary>
void applyForces(b2Body* snake, char* input, int* keysPRessed);

/// <summary>/// moves the target to a new location/// </summary>
void moveTarget(b2Body* target);

bool AABBCollision(b2Body* objA, b2Body* objB);

// Random Methods for a double in a range
float randomFloat();
int randomInt(int a, int b);
float randomFloat(int a, int b);
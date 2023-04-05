#include <iostream>
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Box2D/Box2D.h"
#include "snake.h"

using namespace std;
using namespace sf;

void update(b2World* world, Clock* deltaClock)
{
	Time deltaTime;

	// returns amount of time since last called the restart function
	deltaTime = deltaClock->getElapsedTime();
	deltaClock->restart();

	// Advance the physics world by some amount of time
	// not every console can use 1.0f/60.0f, messes with speed per computer
	world->Step(deltaTime.asSeconds(), 6, 2);

}

void display(b2Body* snake, b2Body* target)
{
	// rounding the position to get a nicer decimal on output
	cout << "Target " << ceil((target->GetPosition().x) * 100.0) / 100.0 << ", " << ceil((target->GetPosition().y) * 100.0) / 100.0 <<
		" --> Snake " << ceil((snake->GetPosition().x) * 100.0) / 100.0 << ", " << ceil((snake->GetPosition().y) * 100.0) / 100.0 << endl;
} 

void applyForces(b2Body* snake, char* input, int* keysPressed)
{
	// Force based on direction, applying force based on input
	b2Vec2 up = b2Vec2(0.0f, 15000.0f);
	b2Vec2 down = b2Vec2(0.0f, -15000.0f);
	b2Vec2 left = b2Vec2(-1000.0f, 0.0f);
	b2Vec2 right = b2Vec2(1000.0f, 0.0f);

	switch (*input)
	{
	case 'W':
	case 'w':
		snake->ApplyForceToCenter(up, true);
		*keysPressed += 1;
		break;

	case 'A':
	case 'a':
		snake->ApplyForceToCenter(left, true);
		*keysPressed += 1;
		break;

	case 'S':
	case 's':
		snake->ApplyForceToCenter(down, true);
		*keysPressed += 1;
		break;

	case 'D':
	case 'd':
		snake->ApplyForceToCenter(right, true);
		*keysPressed += 1;
		break;
	}

}

void moveTarget(b2Body* target)
{
	float x = randomFloat(-5, 5);
	float y = randomFloat(-5, 5);
	target->SetTransform(b2Vec2(x, y), target->GetAngle());
}

bool AABBCollision(b2Body* snake, b2Body* target)
{
	// Max
	b2Vec2 snakeMax = b2Vec2(snake->GetPosition().x + 1, snake->GetPosition().y + 1);
	b2Vec2 targetMax = b2Vec2(target->GetPosition().x + 3, target->GetPosition().y + 3);

	// Min
	b2Vec2 snakeMin = b2Vec2(snake->GetPosition().x - 1, snake->GetPosition().y - 1);
	b2Vec2 targetMin = b2Vec2(target->GetPosition().x - 3, target->GetPosition().y - 3);

	// return true if collided, false otherwise
	if (targetMin.x < snakeMax.x &&
		targetMax.x > snakeMin.x &&
		targetMax.y > snakeMin.y &&
		targetMin.y < snakeMax.y)
	{
		return true;
	}

	return false;
}

float randomFloat()
{
	return (float)(rand()) / (float)(RAND_MAX);
}

int randomInt(int a, int b)
{
	if (a > b)
		return randomInt(b, a);
	if (a == b)
		return a;
	return a + (rand() % (b - a));
}

float randomFloat(int a, int b)
{
	if (a > b)
		return randomFloat(b, a);
	if (a == b)
		return a;

	return (float)randomInt(a, b) + randomFloat();
}
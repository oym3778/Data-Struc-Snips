#include <iostream>
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Box2D/Box2D.h"
#include "snake.h"
#include <conio.h>

using namespace std;
using namespace sf;

int main()
{
	// All of PE5
	 // create the window
	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

	// Green Circle
	sf::CircleShape shape(50);
	// set the shape color to green
	shape.setFillColor(sf::Color(100, 250, 50));
	shape.setPosition(sf::Vector2f(0, 0));

	// Square
	// define a 120x50 rectangle
	sf::RectangleShape rectangle(sf::Vector2f(520, 150));
	// change the size to 100x100
	rectangle.setSize(sf::Vector2f(100, 100));
	rectangle.setPosition(sf::Vector2f(150, 0));
	rectangle.setFillColor(sf::Color(250, 250, 250));

	// define a triangle
	sf::CircleShape triangle(80, 3);
	triangle.setPosition(sf::Vector2f(0, 150));
	triangle.setFillColor(sf::Color(250, 0, 250));

	// define a square
	sf::CircleShape square(80, 4);
	square.setPosition(sf::Vector2f(150, 350));
	square.setFillColor(sf::Color(0, 250, 250));

	// define an octagon
	sf::CircleShape octagon(80, 8);
	octagon.setPosition(sf::Vector2f(350, 350));
	octagon.setFillColor(sf::Color(250, 250, 0));

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}


		// clear the window with black color
		window.clear(sf::Color::Black);

		// draw everything here...
		window.draw(rectangle);
		window.draw(shape);
		window.draw(square);
		window.draw(triangle);
		window.draw(octagon);

		// end the current frame
		window.display();
	}



	return 0; 


	// All of HW 2
	/*// Physical representation of the world holding all attributes of the world
	b2Vec2 gravity(0.0f, -9.8f);
	b2World* world = new b2World(gravity);


	//-------------------------------------------------------------------------
	// Define Bodies, position, damping, etc
	//-------------------------------------------------------------------------
	// Defining Floor Body
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, -17.0f);	//center

	// Defining Ceiling Body
	b2BodyDef ceilingBodyDef;
	ceilingBodyDef.position.Set(0.0f, 18.0f);	// center

	// Defining Left Panel Body
	b2BodyDef leftPanelDef;
	leftPanelDef.position.Set(-18.0f, 11.0f);	// center

	// Defining Right Panel Body
	b2BodyDef rightPanelDef;
	rightPanelDef.position.Set(18.0f, 11.0f);	// center

	// Defining the Player(Snake) Body
	b2BodyDef snakeDef;
	snakeDef.type = b2_dynamicBody;  // dynamic = affected by other forces
	snakeDef.position.Set(0.0f, 9.0f);

	// Defining the Target
	b2BodyDef targetDef;
	//targetDef.type = b2_dynamicBody; // dynamic = affected by other forces
	targetDef.position.Set(-20.0f, 0.0f);

	//-------------------------------------------------------------------------
	// Use world object to create body
	//-------------------------------------------------------------------------
	// Walls
	b2Body* groundBody = world->CreateBody(&groundBodyDef);
	b2Body* ceilingBody = world->CreateBody(&ceilingBodyDef);
	b2Body* leftPanel = world->CreateBody(&leftPanelDef);
	b2Body* rightPanel = world->CreateBody(&rightPanelDef);

	// Player(Snake)
	b2Body* snake = world->CreateBody(&snakeDef);

	// Target
	b2Body* target = world->CreateBody(&targetDef);


	//-------------------------------------------------------------------------
	// Define Fixtures with shape, friction, density, etc
	//-------------------------------------------------------------------------
	// Create Fixture for Top/Bottom Panels
	b2PolygonShape wideBox;
	wideBox.SetAsBox(50.0f, 10.0f);  // 2x as big for x/y

	// Create Fixture for Side Panels
	b2PolygonShape longBox;
	longBox.SetAsBox(10.0f, 50.0f);  // 2x as big for x/y

	// Create Fixture for Player(Snake)
	b2PolygonShape snakeBox;
	snakeBox.SetAsBox(1.0f, 1.0f); // 2x as big for x/y

	b2FixtureDef fixtureSnakeDef;
	fixtureSnakeDef.shape = &snakeBox;
	fixtureSnakeDef.density = 1.0f;
	fixtureSnakeDef.friction = 0.3f;

	// Create Fixture for Target
	b2PolygonShape targetBox;
	targetBox.SetAsBox(2.0f, 2.0f); // 2x as big for x/y


	//-------------------------------------------------------------------------
	// Use fixtures on the body
	//-------------------------------------------------------------------------
	// 0.0f density = static body

	// top/botom fixtures
	groundBody->CreateFixture(&wideBox, 0.0f);
	ceilingBody->CreateFixture(&wideBox, 0.0f);

	// left/right fixtures
	leftPanel->CreateFixture(&longBox, 0.0f);
	rightPanel->CreateFixture(&longBox, 0.0f);

	// Player fixtures
	snake->CreateFixture(&fixtureSnakeDef);

	// Target Fixtures
	target->CreateFixture(&targetBox, 0.0f);


	cout << "Welcome to Gravity Snake!" << endl;
	cout << "Use WASD to apply forces to your snake." << endl;
	cout << "Collect 2 targets to win!" << endl;
	cout << "Press enter to begin." << endl;
	cin.ignore();

	bool running = true;
	int targetFound = 0;
	int keysPressed = 0;
	Clock deltaClock;
	char input;	
	moveTarget(target);
	while (running) {

		update(world, &deltaClock);
		display(snake, target);

		if (AABBCollision(snake, target)) {
			cout << "Target Hit!" << endl;
			moveTarget(target);
			targetFound++;
		}

		if (!_kbhit()) continue;	// returns true if a key is pressed, false otherwise	
		input = _getch();			// Most recently pressed down key
		applyForces(snake, &input, &keysPressed);


		// If target found twice, end the game
		if (targetFound == 2) {
			running = false;
		}
	}

	cout << endl << endl << endl;
	cout << "You win!" << endl;
	cout << "Total keys inputed to apply force: " << keysPressed << endl;
	cin.ignore();
	delete world;
	*/
}
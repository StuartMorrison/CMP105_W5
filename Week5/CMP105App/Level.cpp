#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects

	zomboText.loadFromFile("gfx/animZombie.png");
	zombo.setSize(sf::Vector2f(55, 108));
	zombo.setPosition(200, 200);
	zombo.setTexture(&zomboText);

	zombo.setInput(input);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	zombo.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	zombo.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(zombo);

	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}
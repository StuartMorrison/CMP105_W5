#include "Mario.h"

Mario::Mario()
{
	// Setup walk animation.
	walk.addFrame(sf::IntRect(0, 0, 15, 21));
	walk.addFrame(sf::IntRect(15, 0, 15, 21));
	walk.addFrame(sf::IntRect(30, 0, 15, 21));
	walk.addFrame(sf::IntRect(45, 0, 15, 21));
	walk.setFrameSpeed(1.f / 10.f);

	crouch.addFrame(sf::IntRect(0, 41, 16, 20));
	crouch.addFrame(sf::IntRect(16, 41, 16, 20));
	crouch.setFrameSpeed(5.f / 10.f);

	swim.addFrame(sf::IntRect(0, 22, 16, 20));
	swim.addFrame(sf::IntRect(16, 22, 16, 20));
	swim.addFrame(sf::IntRect(32, 22, 16, 20));
	swim.setFrameSpeed(3.f / 10.f);
}

void Mario::handleInput(float dt)
{
	setVelocity(0.f, 0.f);

	if (input->isKeyDown(sf::Keyboard::D))
	{
		walk.play(true);
		walk.setFlipped(false);
		setVelocity(150.f, 0.f);
		move(getVelocity() * dt);
	}
	else if (input->isKeyDown(sf::Keyboard::A))
	{
		walk.play(true);
		walk.setFlipped(true);
		setVelocity(-150.f, 0.f);
		move(getVelocity() * dt);
	}
	else if (input->isKeyDown(sf::Keyboard::S))
	{
		if (walk.getFlipped() == true)
		{
			crouch.setFlipped(true);
		}
		else
		{
			crouch.setFlipped(false);
		}
		crouch.play(true);
		setVelocity(0.f, 150.f);
		move(getVelocity() * dt);
			
	}
	else if (input->isKeyDown(sf::Keyboard::W))
	{
		if (walk.getFlipped() == true)
		{
			swim.setFlipped(true);
		}
		else 
		{
			swim.setFlipped(false);
		}
		swim.play(true);
		setVelocity(0.f, -150.f);
		move(getVelocity() * dt);
	}
	else
	{
		walk.reset();
		setTextureRect(walk.getCurrentFrame());
		
	}
}

void Mario::update(float dt)
{
	if (input->isKeyDown(sf::Keyboard::D) || input->isKeyDown(sf::Keyboard::A))
	{
		walk.animate(dt);
		setTextureRect(walk.getCurrentFrame());
	}

	if (input->isKeyDown(sf::Keyboard::S))
	{
		crouch.animate(dt);
		setTextureRect(crouch.getCurrentFrame());
	}

	if (input->isKeyDown(sf::Keyboard::W))
	{
		swim.animate(dt);
		setTextureRect(swim.getCurrentFrame());
	}

	
}

Mario::~Mario()
{
}

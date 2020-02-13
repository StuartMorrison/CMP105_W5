#include "Kirby.h"
#include "Mario.h"

Kirby::Kirby()
{
	// Setup walk animation.
	walk.addFrame(sf::IntRect(0, 0, 15, 21));
	walk.addFrame(sf::IntRect(15, 0, 15, 21));
	walk.setFrameSpeed(2.f / 10.f);

	crouch.addFrame(sf::IntRect(32, 0, 32, 32));
	crouch.setFrameSpeed(10.f / 10.f);

	fly.addFrame(sf::IntRect(0, 22, 16, 20));
	fly.addFrame(sf::IntRect(16, 22, 16, 20));
	fly.setFrameSpeed(1.f / 10.f);

	Idle.addFrame(sf::IntRect(0, 0, 32, 32));
	Idle.setFrameSpeed(10.f / 10.f)
}

void Kirby::handleInput(float dt)
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
			fly.setFlipped(true);
		}
		else
		{
			fly.setFlipped(false);
		}
		fly.play(true);
		setVelocity(0.f, -150.f);
		move(getVelocity() * dt);
	}
	else
	{
		walk.reset();
		setTextureRect(walk.getCurrentFrame());

	}
}

void Kirby::update(float dt)
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
		fly.animate(dt);
		setTextureRect(swim.getCurrentFrame());
	}


}

Kirby::~Kirby()
{
}

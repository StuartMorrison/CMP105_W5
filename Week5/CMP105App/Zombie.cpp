#include "Zombie.h"

Zombie::Zombie()
{
	// Setup walk animation.
	walk.addFrame(sf::IntRect(0, 0, 55, 100));
	walk.addFrame(sf::IntRect(55, 0, 55, 100));
	walk.addFrame(sf::IntRect(110, 0, 55, 100));
	walk.addFrame(sf::IntRect(165, 0, 55, 100));
	walk.addFrame(sf::IntRect(220, 0, 55, 100));
	walk.addFrame(sf::IntRect(275, 0, 55, 100));
	walk.addFrame(sf::IntRect(330, 0, 55, 100));
	walk.addFrame(sf::IntRect(385, 0, 55, 100));
	walk.setFrameSpeed(1.f / 10.f);
}

void Zombie::handleInput(float dt)
{
	setVelocity(0.f, 0.f);

	if (input->isKeyDown(sf::Keyboard::Right))
	{
		walk.play(true);
		walk.setFlipped(false);
		setVelocity(150.f, 0.f);
		move(getVelocity() * dt);
	}
	else if (input->isKeyDown(sf::Keyboard::Left))
	{
		walk.play(true);
		walk.setFlipped(true);
		setVelocity(-150.f, 0.f);
		move(getVelocity() * dt);
	}
	else
	{
		walk.pause();
	}
}

void Zombie::update(float dt)
{
	walk.animate(dt);
	setTextureRect(walk.getCurrentFrame());
}

Zombie::~Zombie()
{
}

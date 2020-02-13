#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
class Kirby : public GameObject
{
public:
	Kirby();
	~Kirby();

	void handleInput(float dt) override;
	void update(float dt) override;

protected:
	Animation walk;
	Animation crouch;
	Animation fly;
	Animation Idle;

};


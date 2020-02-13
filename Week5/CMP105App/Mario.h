#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
class Mario : public GameObject
{
public:
		Mario();
		~Mario();

		void handleInput(float dt) override;
		void update(float dt) override;

protected:
	Animation walk;
	Animation crouch;
	Animation swim;
};


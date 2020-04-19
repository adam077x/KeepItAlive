#pragma once

#include "Entity.h"
#include <SFML/Audio.hpp>

struct Generator : Entity {
	static float health, energy;
	static bool playerClose;
	sf::Sound hitSound;
	Entity* p;
	float hitWait;

	Generator(float x, float y);

	void update(float deltaTime) override;
};
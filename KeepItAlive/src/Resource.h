#pragma once

#include <SFML/Audio.hpp>
#include "Entity.h"

struct Resource : Entity {
	sf::Sound hitSound;

	float regenerate;
	bool regenerated;
	int defaultSprite;
	float hitWait;
	Resource(float x, float y);

	void update(float deltaTime) override;
	void addResource();
};
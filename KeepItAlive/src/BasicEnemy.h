#pragma once

#include "Entity.h"
#include "EnemyBase.h"
#include <SFML/Audio.hpp>

struct BasicEnemy : Entity, EnemyBase {
	Entity *target;
	Entity* playerTarget = NULL;
	Entity* generatorTarget = NULL;
	sf::Sound hitSound;
	float hitDelay;

	BasicEnemy(float x, float y);

	void update(float deltaTime) override;
	void mousePressed() override;
	void mouseReleased() override;
};
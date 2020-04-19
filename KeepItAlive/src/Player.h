#pragma once

#include "SFML/Audio.hpp"
#include "Entity.h"

struct Player : Entity {
	sf::Sound respawnSound;
	sf::Sound hitSound;

	float speed;
	static float health;
	static float respawnTime;
	static bool dead;
	static int coal;
	static int iron;
	float hitWait;
	bool stop;
	float directionX;
	float directionY;

	Player(float x, float y);

	void update(float deltaTime) override;
	void render(sf::RenderWindow* window) override;
};
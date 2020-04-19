#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

struct EnemyBase {
	int health;
	EnemyBase(int health);
	bool hold;
	bool hit;
	float hitWait;

	void applyDamage(sf::RectangleShape& collider, sf::Sound &sound);
	void mouseBasePressed();
	void mouseBaseReleased();
};
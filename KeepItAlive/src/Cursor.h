#pragma once
#include <SFML/Graphics.hpp>
#include "AssetManager.h"

struct Cursor {
	int width, height;
	sf::Sprite sprite;
	std::string currentWeapon;

	Cursor();

	void render(sf::RenderWindow* window);
	void update();
};
#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "AssetManager.h"
#include "Entity.h"

struct Game {
	sf::RenderWindow *window;
	float deltaTime;
	sf::Clock clock;
	sf::Clock spawnerClock;

	~Game() = delete;
	
	void start();
	void update();
	void render();
	void close();
	void reload();
};
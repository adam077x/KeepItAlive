#pragma once

#include <vector>
#include <string>
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include "Cursor.h"
#include "InGameMenu.h"

struct GameManager {
	static GameManager *instance;
	static GameManager* getInstance();

	Cursor* cursor;
	InGameMenu* inGameMenu;

	bool gameOver;
	std::vector<Entity*> entities;

	GameManager();

	void update(float deltaTime);
	void render(sf::RenderWindow *window);
	void processEvent(sf::Event &event);
};
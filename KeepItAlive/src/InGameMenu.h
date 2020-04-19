#pragma once

#include <SFML/Graphics.hpp>
#include "Generator.h"
#include "Player.h"

struct InGameMenu {
	/*int generatorHealth;
	int generatorEnergy;
	int playerHealth;*/

	sf::Text respawnText;
	sf::Text coalText;
	sf::Text ironText;
	sf::Text generatorMenu;
	sf::Sprite coal;
	sf::Sprite hearth;
	sf::Sprite energy;
	sf::RectangleShape generatorHealthRect;
	sf::RectangleShape generatorEnergyRect;
	sf::RectangleShape playerHealthRect;
	Generator* generator;
	Player* player;

	InGameMenu();

	void render(sf::RenderWindow* window);
};
#include "InGameMenu.h"
#include "Player.h"
#include "Generator.h"
#include "AssetManager.h"

InGameMenu::InGameMenu()
{
	generatorHealthRect = sf::RectangleShape(sf::Vector2f(Generator::health, 25));
	generatorEnergyRect = sf::RectangleShape(sf::Vector2f(Generator::energy, 25));
	playerHealthRect = sf::RectangleShape(sf::Vector2f(Player::health, 25));

	generatorHealthRect.setFillColor(sf::Color::Black);
	generatorEnergyRect.setFillColor(sf::Color::Yellow);
	playerHealthRect.setFillColor(sf::Color::Red);

	ironText.setFont(AssetManager::getInstance()->getFont("arial"));
	ironText.setCharacterSize(24);
	ironText.setFillColor(sf::Color::White);
	ironText.setString("0");
	ironText.setPosition(0, 75);

	coalText.setFont(AssetManager::getInstance()->getFont("arial"));
	coalText.setCharacterSize(24);
	coalText.setFillColor(sf::Color::White);
	coalText.setString("0");
	coalText.setPosition(0, 101);

	respawnText.setFont(AssetManager::getInstance()->getFont("arial"));
	respawnText.setCharacterSize(24);
	respawnText.setFillColor(sf::Color::White);
	respawnText.setString("0");
	respawnText.setPosition(400, 600);

	generatorMenu.setFont(AssetManager::getInstance()->getFont("arial"));
	generatorMenu.setCharacterSize(24);
	generatorMenu.setFillColor(sf::Color::White);
	generatorMenu.setString("Press C to repair generator\nPress F to add coal to generator");
	generatorMenu.setPosition(250, 548);

	hearth.setTexture(AssetManager::getInstance()->getTexture("hearth"));
	coal.setTexture(AssetManager::getInstance()->getTexture("energyhearth"));
	energy.setTexture(AssetManager::getInstance()->getTexture("energy"));

	hearth.setPosition(0, 29*2);
	coal.setPosition(0, 0);
	energy.setPosition(0, 29);

	generatorHealthRect.setPosition(30, 0);
	generatorEnergyRect.setPosition(30, 25);
	playerHealthRect.setPosition(30, 50);
}

void InGameMenu::render(sf::RenderWindow *window)
{
	generatorHealthRect.setSize(sf::Vector2f(Generator::health, 25));
	generatorEnergyRect.setSize(sf::Vector2f(Generator::energy, 25));
	playerHealthRect.setSize(sf::Vector2f(Player::health, 25));

	if (Player::dead) {
		respawnText.setString(std::to_string((int)Player::respawnTime));
	}

	coalText.setString("Coal: " + std::to_string(Player::coal));
	ironText.setString("Iron: " + std::to_string(Player::iron));

	window->draw(generatorHealthRect);
	window->draw(generatorEnergyRect);
	window->draw(playerHealthRect);
	window->draw(coal);
	window->draw(hearth);
	window->draw(energy);
	window->draw(coalText);
	window->draw(ironText);
	if (Generator::playerClose) {
		window->draw(generatorMenu);
	}
	if (Player::dead) {
		window->draw(respawnText);
	}
}

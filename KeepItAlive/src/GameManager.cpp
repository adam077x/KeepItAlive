#include "GameManager.h"
#include "AssetManager.h"
#include <iostream>
GameManager *GameManager::instance;

GameManager* GameManager::getInstance()
{
	if (instance == NULL)
		instance = new GameManager();

	return instance;
}

GameManager::GameManager()
{
	Player::health = 100;
	Generator::health = 100;
	Generator::energy = 100;
	gameOver = false;

	cursor = new Cursor();
	inGameMenu = new InGameMenu();
}

void GameManager::update(float deltaTime)
{
	if (gameOver) return;

	cursor->update();

	for (int i = 0; i < entities.size(); i++) {
		entities[i]->update(deltaTime);
	}
}

void GameManager::render(sf::RenderWindow* window)
{
	if (gameOver) {
		sf::Sprite gameOverImage;
		gameOverImage.setTexture(AssetManager::getInstance()->getTexture("restartgame"));
		window->draw(gameOverImage);
		return;
	}

	for (int i = 0; i < entities.size(); i++) {
		entities[i]->render(window);
	}

	inGameMenu->render(window);
	cursor->render(window);
}

void GameManager::processEvent(sf::Event &event)
{
	if (gameOver) return;

	if (event.type == sf::Event::MouseButtonPressed) {
		for (int i = 0; i < entities.size(); i++) {
			entities[i]->mousePressed();
		}
	}
	if (event.type == sf::Event::MouseButtonReleased) {
		for (int i = 0; i < entities.size(); i++) {
			entities[i]->mouseReleased();
		}
	}
}

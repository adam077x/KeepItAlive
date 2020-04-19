#include "Generator.h"
#include "GameManager.h"

float Generator::energy;
float Generator::health;
bool Generator::playerClose;

Generator::Generator(float x, float y) : Entity(x, y, 64, 64, "generator")
{
	for (int i = 0; i < GameManager::getInstance()->entities.size(); i++) {
		if (dynamic_cast<Player*>(GameManager::getInstance()->entities.at(i))) {
			p = GameManager::getInstance()->entities.at(i);
		}
	}

	hitSound.setBuffer(AssetManager::getInstance()->getAudio("hitplayer"));
	sprite[1].setTexture(AssetManager::getInstance()->getTexture("generatorflash"));
}

void Generator::update(float deltaTime)
{
	currentSprite = 0;

	energy -= deltaTime * 10;
	if (energy <= 0) {
		GameManager::getInstance()->gameOver = true;
	}
	else if (health <= 0) {
		GameManager::getInstance()->gameOver = true;
	}

	sf::RectangleShape rect = ((Player*)p)->collisionRectangle;
	rect.setPosition(((Player*)p)->directionX*5 + ((Player*)p)->x, ((Player*)p)->directionY*5 + ((Player*)p)->y);
	if (collisionRectangle.getGlobalBounds().intersects(rect.getGlobalBounds())) {
		((Player*)p)->stop = true;
	}

	sf::Vector2f distance = sf::Vector2f(x, y) - sf::Vector2f(p->x, p->y);
	if (abs(distance.x) < 100 && abs(distance.y) < 100) {
		playerClose = true;
	}
	else {
		playerClose = false;
	}

	if (playerClose && sf::Keyboard::isKeyPressed(sf::Keyboard::F) && !Player::dead) {
		if (Player::coal > 0) {
			Player::coal--;
			energy += 20;
		}
	}
	else if (playerClose && sf::Keyboard::isKeyPressed(sf::Keyboard::C) && !Player::dead) {
		if (Player::iron > 0) {
			Player::iron--;
			health += 20;
		}
	}

	if (hitWait > 0) {
		hitWait -= deltaTime;
		currentSprite = 1;
	}
}

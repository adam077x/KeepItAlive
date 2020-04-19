#include "Resource.h"
#include "AssetManager.h"
#include "GameManager.h"

Resource::Resource(float x, float y) : Entity(x, y, 64, 64, "rock")
{
	regenerated = true;
	regenerate = 0;

	defaultSprite = (int)(rand() % 2 + 1);
	addResource();

	sprite[1].setTexture(AssetManager::getInstance()->getTexture("rockcoal"));
	sprite[2].setTexture(AssetManager::getInstance()->getTexture("rockiron"));
	sprite[3].setTexture(AssetManager::getInstance()->getTexture("rockflash"));
	hitSound.setBuffer(AssetManager::getInstance()->getAudio("hitSound"));
}

void Resource::update(float deltaTime)
{
	if (GameManager::getInstance()->cursor->currentWeapon == "pickaxe" && regenerated && !Player::dead) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (GameManager::getInstance()->cursor->sprite.getGlobalBounds().intersects(collisionRectangle.getGlobalBounds())) {
				currentSprite = 0;
				hitWait = 0.05f;
				hitSound.play();
				regenerated = false;
				regenerate = 5;
				if (defaultSprite == 1) {
					Player::coal++;
				}
				else if (defaultSprite == 2) {
					Player::iron++;
				}
			}
		}
	}

	if (hitWait > 0) {
		hitWait -= deltaTime;
		currentSprite = 3;
	} else 	if (hitWait <= 0 && !regenerated) {
		currentSprite = 0;
	}


	if (regenerate > 0) {
		regenerate -= deltaTime;
		regenerated = false;
	}
	else {
		regenerated = true;
		addResource();
	}

	if (regenerated) {
		
	}
}

void Resource::addResource()
{
	currentSprite = defaultSprite;
}

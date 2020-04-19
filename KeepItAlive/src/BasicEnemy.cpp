#include "BasicEnemy.h"
#include "GameManager.h"
#include "Player.h"
#include <cmath>
#include <iostream>
#include "AssetManager.h"

BasicEnemy::BasicEnemy(float x, float y) : Entity(x, y, 64, 56, "zombiefwd"), EnemyBase(3)
{
	sprite[1].setTexture(AssetManager::getInstance()->getTexture("zombieback"));

	sprite[2].setTexture(AssetManager::getInstance()->getTexture("zombiefwdf"));
	sprite[3].setTexture(AssetManager::getInstance()->getTexture("zombiebackf"));

	hitSound.setBuffer(AssetManager::getInstance()->getAudio("hitEnemySound"));

	hitDelay = 0;

	playerTarget = NULL;
	generatorTarget = NULL;

	for (int i = 0; i < GameManager::getInstance()->entities.size(); i++) {
		if (dynamic_cast<Player*>(GameManager::getInstance()->entities.at(i))) {
			playerTarget = GameManager::getInstance()->entities.at(i);
		}
		else if (dynamic_cast<Generator*>(GameManager::getInstance()->entities.at(i))) {
			generatorTarget = GameManager::getInstance()->entities.at(i);
		}
	}
}

void BasicEnemy::update(float deltaTime)
{
	applyDamage(collisionRectangle, hitSound);

	if (currentSprite == 2) {
		currentSprite = 0;
	}
	else if (currentSprite == 3) {
		currentSprite = 1;
	}

	if (sqrt((playerTarget->x - x) * (playerTarget->x - x) + (playerTarget->y - y) * (playerTarget->y - y)) < sqrt((generatorTarget->x - x) * (generatorTarget->x - x) + (generatorTarget->y - y) * (generatorTarget->y - y))) {
		if (!Player::dead) {
			target = playerTarget;
		}
		else {
			target = generatorTarget;
		}
	}
	else {
		target = generatorTarget;
	}

	if (health <= 0) {
		for (int i = 0; i < GameManager::getInstance()->entities.size(); i++) {
			if (GameManager::getInstance()->entities[i]->uniqueId == this->uniqueId) {
				GameManager::getInstance()->entities.erase(GameManager::getInstance()->entities.begin()+i);
			}
		}
	}

	if (!target->collisionRectangle.getGlobalBounds().intersects(collisionRectangle.getGlobalBounds())) {
		float diffX = x - target->x;
		float diffY = y - target->y;
		float length = sqrt(diffX * diffX + diffY * diffY);

		if (diffY > 0) {
			currentSprite = 0;
		}
		else if (diffY < 0) {
			currentSprite = 1;
		}

		diffX /= length;
		diffY /= length;

		x -= diffX * 200 * deltaTime;
		y -= diffY * 200 * deltaTime;
	}
	else {
		if (dynamic_cast<Generator*>(target) && hitDelay <= 0) {
			((Generator*)target)->health -= 5;
			((Generator*)target)->hitWait = 0.05;
			((Generator*)target)->hitSound.play();
			hitDelay = 1;
		}
		else if (dynamic_cast<Player*>(target) && hitDelay <= 0) {
			((Player*)target)->health -= 20;
			((Player*)target)->hitWait = 0.05;
			((Player*)target)->hitSound.play();
			hitDelay = 1;
		}

		hitDelay -= deltaTime;
	}

	if (hit == true) {
		hitWait = 0.05;
	}

	if (hitWait > 0) {
		if (currentSprite == 0) {
			currentSprite = 2;
		}
		else if (currentSprite == 1) {
			currentSprite = 3;
		}
		hit = false;
	}

	hitWait -= deltaTime;
}

void BasicEnemy::mousePressed()
{
	mouseBasePressed();
}

void BasicEnemy::mouseReleased()
{
	mouseBaseReleased();
}

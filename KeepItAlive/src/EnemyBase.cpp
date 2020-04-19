#include "EnemyBase.h"
#include "GameManager.h"
#include "Player.h"

EnemyBase::EnemyBase(int health) : health(health)
{
	hold = false;
	hit = false;
}

void EnemyBase::applyDamage(sf::RectangleShape &collider, sf::Sound &sound)
{
	if (hold) {
		if (collider.getGlobalBounds().intersects(GameManager::getInstance()->cursor->sprite.getGlobalBounds()) && GameManager::getInstance()->cursor->currentWeapon == "sword" && !Player::dead) {
			health -= 1;
			hit = true;
			sound.play();
		}
		hold = false;
	}
}

void EnemyBase::mouseBasePressed()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		hold = true;
	}
}

void EnemyBase::mouseBaseReleased()
{
	hold = false;
}

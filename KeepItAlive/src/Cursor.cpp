#include "Cursor.h"
#include "AssetManager.h"

Cursor::Cursor()
{
	width = 30;
	height = 25;
	sprite.setTexture(AssetManager::getInstance()->getTexture("sword"));
	currentWeapon = "sword";
	//sprite.setScale(sprite.getTexture()->getSize().x / width, sprite.getTexture()->getSize().y / height);
}

void Cursor::render(sf::RenderWindow* window)
{
	sprite.setPosition(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y);
	window->draw(sprite);
}

void Cursor::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
		sprite.setTexture(AssetManager::getInstance()->getTexture("sword"));
		currentWeapon = "sword";
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
		sprite.setTexture(AssetManager::getInstance()->getTexture("pickaxe"));
		currentWeapon = "pickaxe";
	}
}

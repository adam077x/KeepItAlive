#include "Entity.h"
#include "AssetManager.h"

Entity::Entity(float x, float y, int width, int height, std::string texture) : x(x), y(y), width(width), height(height), texture(texture)
{
	currentSprite = 0;
	sprite[0].setTexture(AssetManager::getInstance()->getTexture(texture));
	float sizeX = AssetManager::getInstance()->getTexture(texture).getSize().x;
	float sizeY = AssetManager::getInstance()->getTexture(texture).getSize().y;
	sprite[0].setScale(width / sizeX, height / sizeY);
	uniqueId = rand() % INT_MAX;
	collisionRectangle = sf::RectangleShape(sf::Vector2f(width, height));
}

Entity::~Entity()
{

}

void Entity::render(sf::RenderWindow *window)
{
	collisionRectangle.setPosition(x, y);
	sprite[currentSprite].setPosition(x, y);
	window->draw(sprite[currentSprite]);
}

void Entity::mousePressed()
{
}

void Entity::mouseReleased()
{
}

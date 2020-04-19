#pragma once

#include <SFML/Graphics.hpp>
#include <string>

struct Entity {
	float x, y;
	int width, height;
	std::string texture;
	int currentSprite;
	sf::Sprite sprite[16];
	sf::RectangleShape collisionRectangle;
	int uniqueId;

	Entity(float x, float y, int width, int height, std::string texture);
	~Entity();

	virtual void update(float deltaTime) = 0;
	virtual void render(sf::RenderWindow* window);
	virtual void mousePressed();
	virtual void mouseReleased();
};
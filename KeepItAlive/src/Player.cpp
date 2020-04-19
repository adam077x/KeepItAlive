#include "Player.h"
#include "AssetManager.h"
#include "GameManager.h"
#include "BasicEnemy.h"

float Player::health;
float Player::respawnTime;
bool Player::dead;
int Player::coal;
int Player::iron;

Player::Player(float x, float y) : Entity(x, y, 64, 56, "playerfwd")
{
	speed = 200;
	sprite[1].setTexture(AssetManager::getInstance()->getTexture("playerback"));
	sprite[2].setTexture(AssetManager::getInstance()->getTexture("playerleft"));
	sprite[3].setTexture(AssetManager::getInstance()->getTexture("playerright"));
	sprite[4].setTexture(AssetManager::getInstance()->getTexture("zombiefwdf"));
	hitSound.setBuffer(AssetManager::getInstance()->getAudio("hitplayer"));
	respawnTime = 0;
	dead = false;
	respawnSound.setBuffer(AssetManager::getInstance()->getAudio("respawn"));
	respawnSound.setVolume(1);
	stop = false;
}

void Player::update(float deltaTime)
{
	currentSprite = 1;

	directionX = (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) - (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left));
	directionY = (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) - (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up));

	if (health <= 0 && !dead) {
		respawnTime = 3;
		dead = true;
	}

	if (dead && health > 0) {
		x = 350;
		y = 400;
		dead = false;
		respawnSound.play();
	}

	if (respawnTime <= 0 && dead) {
		health = 100;
	}

	if (respawnTime > 0) {
		respawnTime -= deltaTime;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		currentSprite = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		currentSprite = 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		currentSprite = 2;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		currentSprite = 3;
	}

	if (hitWait > 0) {
		currentSprite = 4;
	}

	hitWait -= deltaTime;
	x += directionX * speed * deltaTime * !stop;
	y += directionY * speed * deltaTime * !stop;

	stop = false;
}

void Player::render(sf::RenderWindow* window)
{
	if (dead) return;
	collisionRectangle.setPosition(x, y);
	sprite[currentSprite].setPosition(x, y);
	window->draw(sprite[currentSprite]);
}

#include "Game.h"
#include "Player.h"
#include "Generator.h"
#include "GameManager.h"
#include "BasicEnemy.h"
#include "Resource.h"

bool run = false;
void Game::start()
{
    window = new sf::RenderWindow(sf::VideoMode(800, 700), "Keep It Alive", sf::Style::Close | sf::Style::Titlebar);
    window->setMouseCursorVisible(false);
    window->setFramerateLimit(60);

    AssetManager::getInstance()->loadTexture("playerfwd", "playerForward.png");
    AssetManager::getInstance()->loadTexture("playerback", "playerBack.png");
    AssetManager::getInstance()->loadTexture("playerleft", "playerLeft.png");
    AssetManager::getInstance()->loadTexture("playerright", "playerRight.png");
    AssetManager::getInstance()->loadTexture("zombiefwd", "zombieForward.png");
    AssetManager::getInstance()->loadTexture("zombieback", "zombieBack.png");
    AssetManager::getInstance()->loadTexture("zombieleft", "zombieLeft.png");
    AssetManager::getInstance()->loadTexture("zombieright", "zombieRight.png");
    AssetManager::getInstance()->loadTexture("zombiefwdf", "zombieForwardFlash.png");
    AssetManager::getInstance()->loadTexture("zombiebackf", "zombieBackFlash.png");
    AssetManager::getInstance()->loadTexture("zombieleftf", "zombieLeftFlash.png");
    AssetManager::getInstance()->loadTexture("zombierightf", "zombieRightFlash.png");
    AssetManager::getInstance()->loadTexture("generator", "generator.png");
    AssetManager::getInstance()->loadTexture("basicenemy", "basicenemy.png");
    AssetManager::getInstance()->loadTexture("sword", "sword.png");
    AssetManager::getInstance()->loadTexture("rock", "rock.png");
    AssetManager::getInstance()->loadTexture("rockcoal", "rockCoal.png");
    AssetManager::getInstance()->loadTexture("rockiron", "rockIron.png");
    AssetManager::getInstance()->loadTexture("restartgame", "RestartGame.png");
    AssetManager::getInstance()->loadTexture("pickaxe", "pickaxe.png");
    AssetManager::getInstance()->loadTexture("coal", "coal.png");
    AssetManager::getInstance()->loadTexture("energy", "energy.png");
    AssetManager::getInstance()->loadTexture("hearth", "hearth.png");
    AssetManager::getInstance()->loadTexture("energyhearth", "generatorHearth.png");
    AssetManager::getInstance()->loadTexture("rockflash", "rockFlash.png");
    AssetManager::getInstance()->loadTexture("generatorflash", "generatorFlash.png");
    AssetManager::getInstance()->loadTexture("tutorial", "tutorial.png");

    AssetManager::getInstance()->loadFont("arial", "arial.ttf");

    AssetManager::getInstance()->loadAudio("respawn", "Respawn.wav");
    AssetManager::getInstance()->loadAudio("hitSound", "hitSound.wav");
    AssetManager::getInstance()->loadAudio("hitplayer", "hitPlayer.wav");
    AssetManager::getInstance()->loadAudio("hitEnemySound", "hitEnemySound.wav");

    reload();

    while (window->isOpen())
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && GameManager::getInstance()->gameOver) {
            reload();
        }

        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) run = true;
            if (run) {
                GameManager::getInstance()->processEvent(event);
            }
        }

        if (run) {
            update();
        }

        window->clear(sf::Color(0, 128, 0));
        
        if (run) {
            render();
        }
        else {
            sf::Sprite sprite;
            sprite.setTexture(AssetManager::getInstance()->getTexture("tutorial"));
            window->draw(sprite);
        }

        window->display();
    }
}

float t = 0;

void Game::update()
{
    sf::Time prevTime;
    sf::Time currentTime = clock.getElapsedTime();

    deltaTime = currentTime.asSeconds();
    GameManager::getInstance()->update(deltaTime);
    t += deltaTime;
    clock.restart();

    sf::Time spawnTime = spawnerClock.getElapsedTime();
    if (spawnTime.asSeconds() >= 1) {
        int r = rand() % 3;
        if (r == 0) {
            GameManager::getInstance()->entities.push_back(new BasicEnemy(rand() % 800, rand() % 700 - 700));
        }
        else if (r == 1) {
            GameManager::getInstance()->entities.push_back(new BasicEnemy(rand() % 800, rand() % 700 + 700));
        }
        else if (r == 2) {
            GameManager::getInstance()->entities.push_back(new BasicEnemy(rand() % 800 - 800, rand() % 700));
        }
        else if (r == 3) {
            GameManager::getInstance()->entities.push_back(new BasicEnemy(rand() % 800 + 800, rand() % 700));
        }
        spawnerClock.restart();
    }
}

void Game::render()
{
    GameManager::getInstance()->render(window);
}

void Game::close()
{

}

void Game::reload()
{
    GameManager::getInstance()->gameOver = false;
    GameManager::getInstance()->entities.clear();

    GameManager::getInstance()->entities.push_back(new Player(400, 400));
    GameManager::getInstance()->entities.push_back(new Generator(window->getSize().x / 2, window->getSize().y / 2 - 64));
    GameManager::getInstance()->entities.push_back(new Resource(234, 182));
    GameManager::getInstance()->entities.push_back(new Resource(454, 641));
    GameManager::getInstance()->entities.push_back(new Resource(51, 316));
    GameManager::getInstance()->entities.push_back(new Resource(701, 64));
    GameManager::getInstance()->entities.push_back(new Resource(91, 350));
    GameManager::getInstance()->entities.push_back(new Resource(156, 24));
    GameManager::getInstance()->entities.push_back(new Resource(64, 182));
    GameManager::getInstance()->entities.push_back(new Resource(480, 128));
    GameManager::getInstance()->entities.push_back(new Resource(612, 286));

    Player::health = 100;
    Generator::health = 100;
    Generator::energy = 100;
    Player::coal = 0;
    Player::iron = 0;
}

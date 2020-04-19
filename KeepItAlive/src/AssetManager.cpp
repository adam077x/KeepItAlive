#include "AssetManager.h"

AssetManager* AssetManager::instance;

AssetManager *AssetManager::getInstance()
{
	if (instance == NULL)
		instance = new AssetManager();

	return instance;
}

void AssetManager::loadTexture(std::string name, std::string path)
{
	sf::Texture texture;
	if (!texture.loadFromFile("res/textures/" + path)) {
	}
	textures[name] = texture;
}

sf::Texture& AssetManager::getTexture(std::string name)
{
	return textures.at(name);
}

void AssetManager::loadFont(std::string name, std::string path)
{
	sf::Font font;
	if (!font.loadFromFile("res/fonts/" + path)) {
	}
	fonts[name] = font;
}

sf::Font& AssetManager::getFont(std::string name)
{
	return fonts.at(name);
}

void AssetManager::loadAudio(std::string name, std::string path)
{
	sf::SoundBuffer soundBuffer;
	if (!soundBuffer.loadFromFile("res/audio/" + path)) {

	}
	audio[name] = soundBuffer;
}

sf::SoundBuffer& AssetManager::getAudio(std::string name)
{
	return audio.at(name);
}

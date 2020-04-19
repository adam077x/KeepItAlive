#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <string>

struct AssetManager {
	static AssetManager *instance;
	static AssetManager *getInstance();

	std::map<std::string, sf::Texture> textures;
	void loadTexture(std::string name, std::string path);
	sf::Texture& getTexture(std::string name);

	std::map<std::string, sf::Font> fonts;
	void loadFont(std::string name, std::string path);
	sf::Font& getFont(std::string name);

	std::map<std::string, sf::SoundBuffer> audio;
	void loadAudio(std::string name, std::string path);
	sf::SoundBuffer& getAudio(std::string name);
};
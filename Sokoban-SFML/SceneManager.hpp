#pragma once

#include <map>
#include <memory>
#include <string>
#include <exception>
#include <SFML/Graphics.hpp>

class SceneManager {
private:
	std::map<std::string, std::unique_ptr<sf::Texture>> _textures;
	std::map<std::string, std::unique_ptr<sf::Font>> _fonts;
public:
	SceneManager();
	~SceneManager();

	void AddTexture(const std::string& name, const std::string& filePath, bool repeatFlag = false);
	void AddFont(const std::string& name, const std::string& filePath);


	const sf::Texture& getTexture(const std::string& name) const;
	const sf::Font& getFont(const std::string& name) const;
};


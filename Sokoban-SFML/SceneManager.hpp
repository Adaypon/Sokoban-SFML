#pragma once

#include <map>
#include <string>
#include <exception>
#include <SFML/Graphics.hpp>

class SceneManager {
private:
	std::map<std::string, std::unique_ptr<sf::Texture>> _textures;
public:
	SceneManager();
	~SceneManager();

	void AddTexture(const std::string& name, const std::string& filePath, bool repeatFlag = false);

	const sf::Texture& getTexture(const std::string& name) const;
};


#pragma once

#include <map>
#include <string>
#include <SFML/Graphics.hpp>

class SceneManager {
private:
	std::map<std::string, sf::Texture*> _textures;
public:
	SceneManager();
	~SceneManager();

	void AddTexture(const std::string& name, const std::string& filePath, bool repeatFlag = false);

	sf::Texture* getTexture(const std::string& name) const;
};


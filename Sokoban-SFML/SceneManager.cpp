#include "SceneManager.hpp"

SceneManager::SceneManager() :
	_textures()
{
	
}

SceneManager::~SceneManager() {

}

void SceneManager::AddTexture(const std::string& name, const std::string& filePath, bool repeatFlag) {
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile(filePath);
	texture->setRepeated(repeatFlag);
	_textures.insert(std::make_pair(name, texture));
}

sf::Texture* SceneManager::getTexture(const std::string& name) const {
	auto it = _textures.find(name);
	return (it != _textures.end()) ? it->second : nullptr;
}

#include "SceneManager.hpp"

SceneManager::SceneManager() :
	_textures()
{
	
}

SceneManager::~SceneManager() {

}

void SceneManager::AddTexture(const std::string& name, const std::string& filePath, bool repeatFlag) {
	auto texture = std::make_unique<sf::Texture>(); 

	if (texture->loadFromFile(filePath)) { 
		texture->setRepeated(repeatFlag);
		_textures[name] = std::move(texture);
	}
	else {
		throw std::runtime_error("Unable to load the texture file");
	}
}

const sf::Texture& SceneManager::getTexture(const std::string& name) const {
	return *(_textures.at(name).get());
}

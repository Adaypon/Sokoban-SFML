#include "SceneManager.hpp"

SceneManager::SceneManager() :
	_textures(),
	_fonts()
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

void SceneManager::AddFont(const std::string& name, const std::string& filePath) {
	auto font = std::make_unique<sf::Font>();
	if (font->loadFromFile(filePath)) {
		_fonts[name] = std::move(font);
	}
	else {
		throw std::runtime_error("Unable to load the font file");
	}
}

const sf::Texture& SceneManager::getTexture(const std::string& name) const {
	return *(_textures.at(name).get());
}

const sf::Font& SceneManager::getFont(const std::string& name) const {
	return *(_fonts.at(name).get());
}
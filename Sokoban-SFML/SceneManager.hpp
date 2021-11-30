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

	/**
	* Add texture
	* @param name Name of the texture asset
	* @param filePath File path to the texture asset
	* @param repeatFlag Boolean that allows the texture to be repeated to fill rectangle
	*/
	void AddTexture(const std::string& name, const std::string& filePath, bool repeatFlag = false);
	
	/**
	* Add font
	* @param name Name of the font asset
	* @param filePath File path to the font asset
	*/
	void AddFont(const std::string& name, const std::string& filePath);

	/**
	* Get texture
	* @param name Name of the texture asset
	* @return Const reference of the texture asset
	*/
	const sf::Texture& getTexture(const std::string& name) const;

	/**
	* Get font
	* @param name Name of the font asset
	* @return Const reference of the font asset
	*/
	const sf::Font& getFont(const std::string& name) const;
};


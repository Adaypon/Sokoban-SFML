#pragma once

#include <TGUI/TGUI.hpp>
#include <fstream>
#include <algorithm>
#include "State.hpp"
#include "Game.hpp"
class SettingsMenuState : public State
{
private:
	std::shared_ptr<Context> _context;
	tgui::GuiSFML _gui;
	tgui::ComboBox::Ptr _resolutionComboBox;
	bool isResolutionChanged = false;
public:
	SettingsMenuState(std::shared_ptr<Context>& context);

	void init() override;
	void handleInput(const sf::Time deltaTime) override;
	void update(const sf::Time deltaTime) override;
	void render() override;

	void updateSFMLEvents(sf::Event& SFMLEvent) override;
	void callBackButton();
};
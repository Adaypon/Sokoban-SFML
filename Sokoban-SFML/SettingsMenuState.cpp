#include "SettingsMenuState.hpp"

SettingsMenuState::SettingsMenuState(std::shared_ptr<Context>& context) :
    _context(context)
{

}

// TODO handleEvent

void SettingsMenuState::init() {
    _gui.setTarget(*(_context->_window.get()));

    auto comboBox = tgui::ComboBox::create();
    comboBox->setSize(120, 21);
    comboBox->setPosition(420, 40);
    comboBox->addItem("Item 1");
    comboBox->addItem("Item 2");
    comboBox->addItem("Item 3");
    comboBox->setSelectedItem("Item 2");
    _gui.add(comboBox);

    auto button = tgui::Button::create();
    button->setPosition(_gui.getView().getSize().x - 115.f, _gui.getView().getSize().y - 50.f);
    button->setText("Exit");
    button->setSize(100, 40);

    
    _gui.add(button);
}

void SettingsMenuState::handleInput(const sf::Time deltaTime) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        _context->_states->popState();
    }
}

void SettingsMenuState::update(const sf::Time deltaTime) {
    handleInput(deltaTime);
}

void SettingsMenuState::render() {
    _gui.mainLoop(); // TODO break main loop
}
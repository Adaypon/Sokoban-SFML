#include "SettingsMenuState.hpp"

SettingsMenuState::SettingsMenuState(std::shared_ptr<Context>& context) :
    _context(context)
{

}

void SettingsMenuState::init() {
    _context->_window->clear(sf::Color(189, 189, 189));
    _gui.setTarget(*(_context->_window.get()));

    auto videoModes = sf::VideoMode::getFullscreenModes();
    _resolutionComboBox = tgui::ComboBox::create();
    _resolutionComboBox->setSize(120, 21);
    _resolutionComboBox->setPosition(115.f, 50.f);
    for (auto& mode : videoModes) {
        _resolutionComboBox->addItem(std::to_string(mode.width) + "x" + std::to_string(mode.height));
    }
    
    _resolutionComboBox->setSelectedItem(std::to_string((int)_gui.getView().getSize().x) + "x" + std::to_string((int)_gui.getView().getSize().y));
    _gui.add(_resolutionComboBox);

    auto button = tgui::Button::create();
    button->setPosition(_resolutionComboBox->getPosition().x, _resolutionComboBox->getPosition().y + 100.f);
    button->setText("Back to Menu");
    button->setSize(100, 40);
    button->onPress([&] { 
        std::ofstream fout;
        fout.open("config.ini");
        if (fout.is_open()) {
            auto resolution = _resolutionComboBox->getSelectedItem();
            auto width = resolution.substr(0, resolution.find('x'));
            auto height = resolution.substr(resolution.find('x') + 1);

            fout << width << std::endl;
            fout << height << std::endl;
        }
        else {
            std::cerr << "Can't open file config.ini" << std::endl;
        }
        fout.close();
        _context->_states->popState();
        });
    _gui.add(button);


    auto label = tgui::Label::create();
    label->setText("* Changing resolution requires restarting of the game");
    label->setPosition(_resolutionComboBox->getPosition().x + 125.f, _resolutionComboBox->getPosition().y);
    label->setTextSize(14);
    _gui.add(label);
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
    _context->_window->clear(sf::Color(189, 189, 189));
    _gui.draw();
}

void SettingsMenuState::updateSFMLEvents(sf::Event& SFMLEvent) {
    _gui.handleEvent(SFMLEvent);
}


void SettingsMenuState::callBackButton() {
    std::ofstream fout;
    fout.open("config.ini");
    if (fout.is_open()) {
        auto resolution = _resolutionComboBox->getSelectedItem();
        auto width = resolution.substr(0, resolution.find('x'));
        auto height = resolution.substr(resolution.find('x') + 1);

        fout << width << std::endl;
        fout << height << std::endl;
    }
    else {
        std::cerr << "Can't open file config.ini" << std::endl;
    }
    fout.close();
    _context->_states->popState();
}
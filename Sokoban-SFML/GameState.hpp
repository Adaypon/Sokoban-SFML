#pragma once

#include <fstream>
#include <memory>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <algorithm>
#include "State.hpp"
#include "Player.hpp"
#include "Box.hpp"
#include "Wall.hpp"
#include "Goal.hpp"
#include "Free.hpp"
#include "Game.hpp"

class GameState : public State
{
private:
    std::shared_ptr<Context> _context;
    int _levelNum;
    std::vector<std::string> _boardData;
    int _widthOfGridLine;
    int _heightOfGridLine;
    
    sf::Sprite _background;
    sf::Sprite _sprite;

    float _offsetX = 0;
    float _offsetY = 0;

    int _levelsCount = 4;

    sf::Text _debugText;

    bool _win = false;
    bool _boxTrouble = false;
public:
    GameState(std::shared_ptr<Context>& context, int levelNum);
    //~GameState();

    void init() override;
    void handleInput(const sf::Time deltaTime) override;
    void update(const sf::Time deltaTime) override;
    void render() override;
    void pause() override;
    void resume() override;

    enum CellData {
        WallCell,
        BoxCell,
        BoxOnGoalCell,
        FreeCell,
        GoalCell,
        BGCell,
        PlayerCell
    };

    int getNumOfSprite(int i, int j);
    const int widthOfSprite = 60;
    const int heightOfSprite = 60;
};
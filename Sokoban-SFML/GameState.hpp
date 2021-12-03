#pragma once

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
    
    sf::Sprite _background;
    sf::Sprite _sprite;

    float _offsetX = 0;
    float _offsetY = 0;
public:
    GameState(std::shared_ptr<Context>& context);
    //~GameState();

    void init() override;
    void handleInput(const sf::Time deltaTime) override;
    void update(const sf::Time deltaTime) override;
    void render(sf::RenderWindow* window) override;
    void pause() override;
    void resume() override;

    // Just for testing
    // ____________________________________________________________

    enum CellData {
        WallCell,
        BoxCell,
        BoxOnGoalCell,
        FreeCell,
        GoalCell,
        BGCell,
        PlayerCell
    };

    /*
    std::vector<std::string> board1 = {
        "#######",
        "#@....#",
        "#.....#",
        "#..B..#",
        "#.xB..#",
        "#..x..#",
        "#######"
    };
    */
    
    

    std::vector<std::string> board1 = {
        "//###////",
        "//#x#////",
        "//#.####/",
        "###B.Bx#/",
        "#x.B@###/",
        "####B#///",
        "///#x#///",
        "///###///",
        "/////////"
    };


    int getNumOfSprite(int i, int j);
    const int widthOfSprite = 60;
    const int heightOfSprite = 60;
    const int widthOfGridLine = board1[0].size();
    const int heightOfGridLine = board1.size();

    // ____________________________________________________________
};
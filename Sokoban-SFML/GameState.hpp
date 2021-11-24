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

//struct Context;

class GameState : public State
{
private:
    std::shared_ptr<Context> _context;
    //Entity _player;

    sf::Sprite _background;
    sf::Sprite _sprite;

    //std::vector<Entity*> _objects;
public:
    GameState(std::shared_ptr<Context>& context);
    //~GameState();

    void init() override;
    void handleInput(const sf::Time deltaTime) override;
    void update(const sf::Time deltaTime) override;
    void render(sf::RenderWindow* window) override;
    void pause() override;
    void resume() override;

    //void createObject(Entity* object);

    // TODO Cells as entities

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


    std::vector<std::string> board1 = {
        "#######",
        "#.....#",
        "#..@..#",
        "#..B..#",
        "#.....#",
        "#..x..#",
        "#######"
    };


    int getNumOfSprite(int i, int j);
    const int widthOfSprite = 60;
    const int sizeOfGridLine = 7;

    // ____________________________________________________________
};
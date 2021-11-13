#pragma once

#include <memory>
#include <vector>
#include <string>
#include "State.hpp"
#include "Entity.hpp"
#include "Game.hpp"

struct Context;

class GameState : public State
{
private:
	std::shared_ptr<Context> _context;
	Entity _player;

    sf::Sprite _background;
    sf::Sprite _sprite;
public:
	GameState(std::shared_ptr<Context>& context);
	~GameState();

	void init() override;
	void handleInput(const sf::Time deltaTime) override;
	void update(const sf::Time deltaTime) override;
	void render(sf::RenderWindow* window) override;

    // TODO Cells as entities
    
    // Just for testing
    // ____________________________________________________________

    enum CellData {
        Wall,
        Box,
        BoxOnGoal,
        Free,
        Goal,
        BG,
        Player
    };


    std::vector<std::string> board1 = {
        "#######",
        "#.....#",
        "#.....#",
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


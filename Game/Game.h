#pragma once

#include "../Board/Board.h"
#include "../OpponentFactory/OpponentFactory.h"
#include "../Player/Player.h"
#include "../ShopFactory/ShopFactory.h"

class Shop;

class Game
{
public:
    void start();
    void next_turn();
    bool is_game_over();
private:
    Board board;
    ShopFactory shop_factory;
    Shop* current_shop;
    Player player;
    OpponentFactory opponent_factory;
    Player* current_opponent;
};

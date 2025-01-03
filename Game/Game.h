#pragma once

#include "../Board/Board.h"
#include "../PieceFactory/PieceFactory.h"
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
    void select_piece(int x, int y);

    Board board;
    ShopFactory shop_factory;
    Shop* current_shop;
    Player player;
    PieceFactory piece_factory;
    Player* current_opponent;
    UI ui;
};

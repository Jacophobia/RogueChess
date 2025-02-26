#pragma once

#include "../Board/Board.h"
#include "../PieceFactory/PieceFactory.h"
#include "../Player/Player.h"
#include "../ShopFactory/ShopFactory.h"

class Shop;

class Game
{
public:
    Game();
    
    void start();
    void next_turn();
    bool is_game_over();
    void close();
private:
    std::vector<ValidMove> select_piece(int x, int y, bool should_valid_moves_be_shown);

    void test_setup();
    
    Board board;
    ShopFactory shop_factory;
    Shop* current_shop;
    Player player;
    PieceFactory piece_factory;
    Player* current_opponent;
    UI ui;

    bool could_the_game_be_possibly_over = false;
};

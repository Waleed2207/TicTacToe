#pragma once
#include <iostream>
#include "boardGame.h"

class TicTacToe :public BoardGame{

public:
    TicTacToe():BoardGame(3,3){}
    void set_player_move(Move & m);
     bool is_valid_move(Move &m)const ;
    bool is_game_end();

private:
bool is_X_won_row()const;
bool is_O_won_row() const;
bool is_X_won_col() const;
bool is_O_won_col() const;
bool is_X_won_slant()const;
bool is_O_won_slant()const;
bool is_game_end_tie()const;

};
// void set_player_computer(Move & m)
// GameState get_game_state()



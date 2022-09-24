#pragma once
#include <iostream>
#include "move.h"
enum GameState { PlayerWins, ComputerWins, Tie, InProgress};
enum UI {Console=1,Graphical};

class Game
{
public:
    Game(){};
    virtual void set_player_move(Move & m)=0;
    virtual void set_computer_move()=0;
    virtual GameState get_game_state()const =0; 
    virtual bool is_valid_move(Move &m) const =0 ;
    virtual bool is_game_end() =0;
    virtual void show_game(UI showGameOption) const =0;
    virtual void print_game_end(UI showGameOption) const =0;
    virtual Move& try_move()=0;
    
protected:
 Move m_move;   
GameState m_state;

};


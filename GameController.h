#pragma once
#include <iostream>
#include "TicTacToeLowLevel.h"
#include "TicTacToeHighLevel.h"
#include <memory>

using namespace std;

class GameController
{

public:
    void play();

private:
shared_ptr<Game> curr_game;    
};



#pragma once
#include <iostream>
#include "TicTacToe.h"

class TicTacToeLowLevel : public TicTacToe
{

public:
TicTacToeLowLevel():TicTacToe(){}
    void set_computer_move();

};

#include "TicTacToeLowLevel.h"

void TicTacToeLowLevel:: set_computer_move() 
    {
        bool valid_move = false;
        while (!valid_move)
        {
            int computer_choice = (rand() % 9) + 1;
            int row = (computer_choice - 1) / 3;
            int col = (computer_choice - 1) % 3;

            char board_position = m_board[row][col];
            if (board_position == 'X' || board_position == 'O'){ //This position is alerady taken
                continue;
            }
            else
            {// Find free place to computer
                valid_move = true;
                m_board[row][col] = 'O';
            }
        }
    }
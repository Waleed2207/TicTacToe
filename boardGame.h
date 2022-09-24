#pragma once
#include <iostream>
#include "game.h"
#include <memory>
#include <vector>

using namespace std;

class BoardGame : public Game
{

public:
    BoardGame(int col, int row) : m_col(col), m_row(row)
    {
        m_board.resize(m_row, vector<char>(m_col, '-'));
    }

    void show_game(UI showGameOption)const
    {
        if(showGameOption==Console)
        {
             for (int i = 0; i < m_board.size(); i++)
        {
            for (int j = 0; j < m_board.size(); j++)
            {
                cout << m_board[i][j];
                cout << ' ';
            }
            cout << endl;
        }
        }
        else if (showGameOption==Graphical)
        {
            cout<<"This option is not available right now"<<endl;
        }
       
    }

    GameState get_game_state()const
    {
        return m_state;
    }

    void print_game_end(UI showGameOption)const{

        if(showGameOption==Console){

             if(get_game_state()==PlayerWins)
                cout<<"you win!"<<endl;
           
            else if(get_game_state()==ComputerWins)
                cout<<"you are looser!"<<endl;  

            else if(get_game_state()==Tie)
                cout<<"It's a Tie !"<<endl;

            show_game(showGameOption);
            cout<<endl;
        }

         else if (showGameOption==Graphical)
        {
            cout<<"This option is not available right now"<<endl;
        }
        
    }

    Move& try_move()
    {
        char comma;
        int row, col;
        cout << "Enter position Row,Col: ";
            cin >> row;
            cin >> comma;
            cin >> col;

        m_move.set_x(row - 1);
        m_move.set_y(col - 1);

        return m_move;
    }

protected:
    vector<vector<char>> m_board;
    int m_col;
    int m_row;
};

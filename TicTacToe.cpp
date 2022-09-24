#include <iostream>
#include "TicTacToe.h"

// GameState get_game_state()
bool TicTacToe::is_valid_move(Move &m) const
{
    if (m.get_x() != 0 && m.get_x() != 1 && m.get_x() != 2)
    {
        cerr << "Invalid Move"<<endl;
        return false;
    }

    if (m.get_y() != 0 && m.get_y() != 1 && m.get_y() != 2){
        cerr << "Invalid Move"<<endl;
        return false;
    }

    if (m_board[m.get_x()][m.get_y()] != '-'){
        cerr << "Invalid Move"<<endl;
        return false;
    }
    return true;
}

void TicTacToe::set_player_move(Move &m)
{
    if (!is_valid_move(m))
    {
        cerr << "Invalid Move";
        throw "Invalid Move";
    }
    // m_move.set_x(m.get_x());
    // m_move.set_y(m.get_y());
    m_board[m.get_x()][m.get_y()]='X';
}



bool TicTacToe::is_X_won_row() const
{
    int counter = 0;
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            if (m_board[i][j] == 'X')
            {
                counter++;
            }
        }
        if (counter == 3)
        {
            return true;
        }
        counter = 0;
    }
    return false;
}

bool TicTacToe::is_O_won_row() const
{
    int counter = 0;
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            if (m_board[i][j] == 'O')
            {
                counter++;
            }
        }
        if (counter == 3)
        {
            return true;
        }
        counter = 0;
    }
    return false;
}

bool TicTacToe::is_X_won_col() const
{
    int counter = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (m_board[i][j] == 'X')
            {
                counter++;
            }
        }
        if (counter == 3)
        {
            return true;
        }
        counter = 0;
    }
    return false;
}

bool TicTacToe::is_O_won_col() const
{
    int counter = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (m_board[i][j] == 'O')
            {
                counter++;
            }
        }
        if (counter == 3)
        {
            return true;
        }
        counter = 0;
    }
    return false;
}

bool TicTacToe::is_X_won_slant() const
{
    int counter = 0;
    for (int j = 0, i = 0; j < 3; j++, i++)
    {
        if (m_board[i][j] == 'X')
        {
            counter++;
        }
    }
    if (counter == 3)
    {
        return true;
    }
    counter = 0;

    for (int j = 0, i = 2; j < 3; j++, i--)
    {
        if (m_board[i][j] == 'X')
        {
            counter++;
        }
    }
    if (counter == 3)
    {
        return true;
    }
    return false;
}

bool TicTacToe::is_O_won_slant() const
{
    int counter = 0;
    for (int j = 0, i = 0; j < 3; j++, i++)
    {
        if (m_board[i][j] == 'O')
        {
            counter++;
        }
    }
    if (counter == 3)
    {
        return true;
    }

    counter = 0;

    for (int j = 0, i = 2; j < 3; j++, i--)
    {
        if (m_board[i][j] == 'O')
        {
            counter++;
        }
    }
    if (counter == 3)
    {
        return true;
    }
    return false;
}

bool TicTacToe::is_game_end_tie() const
{
    int counter = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (m_board[i][j] == '-')
            {
                return false;
            }
        }
    }
    return true;
}

bool TicTacToe::is_game_end() 
{

    
    if (is_X_won_row() || is_X_won_col() || is_X_won_slant())
    {
        m_state = PlayerWins;
        return true;
    }
    
    else if (is_O_won_row() || is_O_won_col()|| is_O_won_slant())
    {
        m_state = ComputerWins;
        return true;
    }
   
    else if (is_game_end_tie())
    {
        m_state = Tie;
        return true;
    }
    m_state=InProgress;
    return false;
}

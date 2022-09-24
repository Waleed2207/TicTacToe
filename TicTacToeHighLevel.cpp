#include "TicTacToeHighLevel.h"

void TicTacToeHighLevel::set_O()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (m_board[i][j] == '*')
            {
                m_board[i][j] = 'O';
            }
        }
    }
}

bool TicTacToeHighLevel::check_Rows(char temp)
{
    int counter = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (m_board[i][j] == temp)
            {
                counter++;
            }
        }
        if (counter == 2)
        {
            for (int j = 0; j < 3; j++)
            {
                if (m_board[i][j] == '-')
                {
                    m_board[i][j] = '*';
                    return true;
                }
            }
        }
        counter = 0;
    }
    return false;
}

bool TicTacToeHighLevel::check_Cols(char temp)
{
    int counter = 0;
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            if (m_board[i][j] == temp)
            {
                counter++;
            }
        }
        if (counter == 2)
        {
            for (int i = 0; i < 3; i++)
            {
                if (m_board[i][j] == '-')
                {
                    m_board[i][j] = '*';
                    return true;
                }
            }
        }
        counter = 0;
    }
    return false;
}

bool TicTacToeHighLevel::check_Slants(char temp)
{
    int counterA = 0;
    int counterB = 0;
    for (int j = 0, i = 0; j < 3; j++, i++)
    {
        if (m_board[i][j] == temp)
        {
            counterA++;
        }
    }
    if (counterA == 2)
    {
        for (int j = 0, i = 0; j < 3; j++, i++)
        {
            if (m_board[i][j] == '-')
            {
                m_board[i][j] = '*';
                return true;
            }
        }
        counterA = 0;
    }
    else
    {
        for (int j = 0, i = 2; j < 3; j++, i--)
        {
            if (m_board[i][j] == temp)
            {
                counterB++;
            }
        }
        if (counterB == 2)
        {
            for (int j = 0, i = 2; j < 3; j++, i--)
            {
                if (m_board[i][j] == '-')
                {
                    m_board[i][j] = '*';
                    return true;
                }
            }
            counterB = 0;
        }
    }
    return false;
}

void TicTacToeHighLevel::set_computer_move()
{
    //to victory
    if (check_Rows('O')) //A move to victory
    {
        set_O();
    }
    else if (check_Cols('O')) //A move to victory
    {
        set_O();
    }
    else if (check_Slants('O')) //A move to victory
    {
        set_O();
    }

    //to block
    else if (check_Rows('X')) //Block player
    {
        set_O();
    }
    else if (check_Cols('X')) //Block player
    {
        set_O();
    }
    else if (check_Slants('X')) //Block player
    {
        set_O();
    }

    else
    {
        bool vlaid_move = false;
        while (!vlaid_move)
        {
            int computer_choice = (rand() % 9) + 1;
            int row = (computer_choice - 1) / 3;
            int col = (computer_choice - 1) % 3;
            char grid_position = m_board[row][col];
            if (grid_position == 'X' || grid_position == 'O')
            {
                //This position is alerady taken
                continue;
            }
            else
            {
                vlaid_move = true;
                m_board[row][col] = 'O';
            }
        }
    }
}
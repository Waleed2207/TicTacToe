#include "GameController.h"

void GameController::play()
{
    cout<<endl;
    cout<<endl;
    cout << "-------------------------------------------------Hello World---------------------------------------------------------------------------- " << endl;
    while(1)
    {

    cout << "Please! You Should start Playing Press 1: " << endl;
    int chooseGame;
    cin >> chooseGame;
    while (chooseGame != 1)
    {
        cerr << "Invalid , try again" << endl;
        cin >> chooseGame;
    }

    int chooseDifficulty;
    cout << "------------------------------------------------Welcome To Tic Tac Toe Game------------------------------------------------------------" << endl;
    cout << "Please choose Difficulty: " << endl;
    cout << "1. Easy " << endl;
    cout << "2. Meduim " << endl;
    cin >> chooseDifficulty;
    while (chooseDifficulty != 1 && chooseDifficulty != 2)
    {
        cerr << "Invalid game,please try again" << endl;
        cin >> chooseDifficulty;
        break;
    }

    if (chooseGame == 1 && chooseDifficulty == 1)
    {
        // shared_ptr<Game> g= new TicTacToeLowLevel();
        curr_game = shared_ptr<Game>(new TicTacToeLowLevel());
    }

    else if (chooseGame == 1 && chooseDifficulty == 2)
    {
        curr_game = shared_ptr<Game>(new TicTacToeHighLevel);
    }

     UI optionSelected;
     int chooseView;
    cout << "Please choose view option: " << endl;
    cout << "1. Console " << endl;
    cout << "2. Graphical " << endl;
    cin >> chooseView;
     while (chooseView != 1)
    {
        if(chooseView==2){
            cerr<<"This option is not available right now"<<endl;
        }
        else {
             cerr << "Invalid option,please try again!" << endl;
        }
        cout << "Please choose view option: " << endl;
        cin >> chooseView;
    }
    optionSelected=Console;
    
    
    Move playerMove;
    while (!curr_game->is_game_end())
    {
        cout << endl;
        curr_game->show_game(optionSelected);

        do
        {
            playerMove= curr_game->try_move();
        } while (!(curr_game->is_valid_move(playerMove)));

        curr_game->set_player_move(playerMove);

        if (curr_game->is_game_end())
        {
            curr_game->print_game_end(optionSelected);
            break;
        }
        curr_game->set_computer_move();

        if (curr_game->is_game_end())
        {
            curr_game->print_game_end(optionSelected);
            break;
        }
    }
}
}
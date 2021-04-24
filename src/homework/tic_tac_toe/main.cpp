#include <iostream>
#include <string>
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_3.h"

using std::string;
using std::cout;
using std::cin;

int main()
{
    cout<<"***********************\n"
        <<"WELCOME TO TIK TAC TOE\n"
        <<"***********************\n"
        <<"\n";

    string choice;
    string re_run_game;
    TicTacToeManager manager;
    unique_ptr<TicTacToe>game_play;

    do {
        string game_mode;

        do
        {
            cout << "Would you like to play game 3 or 4?";
            cin >> game_mode;

            // input invalidation error message
            if (!(game_mode == "3" || game_mode == "4")) {
                cout << "**INVALID ENTRY!**\n"
                     << "\n";
            }
        }while (!(game_mode == "3" || game_mode == "4"));

        if (game_mode == "3")
        {
            game_play = std::make_unique<TicTacToe3>();
        }
        if (game_mode == "4")
        {
            game_play = std::make_unique<TicTacToe4>();
        }

        // input validation loop if user  does not select, X or O
        do {
            cout << "Would you like to be X or O: ";
            cin >> choice;
            cout << "\n";

            // input invalidation error message
            if (!(choice == "X" || choice == "O")) {
                cout << "**INVALID ENTRY!**\n"
                     << "\n";
            }
        } while (!(choice == "X" || choice == "O"));

        // sets first_player to user choice of X or O
        game_play->start_game(choice);

        // loop that alternates player turn
        do
        {
            cin >> *game_play;
            cout << *game_play;

            //loops until game is over not true
        } while (!game_play->game_over());

        cout<<game_play->get_winner()<<" wins! Game Over!"<<"\n"<<"\n";
        choice = "";
        manager.save_game(game_play);

        int o, x, t;
        manager.get_winner_total(o,x,t);

        cout<<manager;

        do {
                cout << "Play again(Y/N)? ";
                cin >> re_run_game;
                cout << "\n";

                // input invalidation error message
                if (!(re_run_game == "Y" || re_run_game == "y" ||
                      re_run_game == "N" || re_run_game == "n")) {
                    cout << "**INVALID ENTRY!**\n"
                         << "\n";
                }
            } while (!(re_run_game == "Y" || re_run_game == "y" ||
                       re_run_game == "N" || re_run_game == "n"));

            //continues game play loop until user declines
    }while (re_run_game == "Y" || re_run_game == "y");

    cout<<"(-_-)\n"
        <<"≤))≥\n"
        << "_| \\_\n"
        <<"Well...you're no fun!\n"
        <<"\n"
        <<"Program terminated by user...\n";

    return 0;
}
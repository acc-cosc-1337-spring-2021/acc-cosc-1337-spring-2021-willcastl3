#include <iostream>
#include <string>
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"

using std::string;
using std::cout;
using std::cin;

int main()
{
    cout<<"***********************\n"
        <<"WELCOME TO TIK TAC TOE\n"
        <<"***********************\n"
        <<"\n";

    string re_run_game;

    //creates instance of TicTacToeManager class
    TicTacToeManager manager;
    do
    {
        //creates instance of TicTacToe class
        TicTacToe game_play;
        // initializes variables for user choice and position on board
        string choice;

        // input validation loop if user  does not select, X or O
        do
        {
            cout<<"Would you like to be X or O: ";
            cin>>choice;
            cout<<"\n";

            // input invalidation error message
            if(!(choice =="X" || choice =="O"))
            {
                cout<<"**INVALID ENTRY!**\n"
                    << "\n";
            }
        }while(!(choice =="X" || choice =="O"));

        // sets first_player to user choice of X or O
        game_play.start_game(choice);

        // loop that alternates player turn
        do
        {
            cin>>game_play;
            cout<<game_play;

        //loops until game is over not true
        } while(!game_play.game_over());

        cout<<game_play.get_winner()<<" wins! Game Over!"<<"\n"<<"\n";
        choice = "";
        manager.save_game(game_play);

        int o, x, t;
        manager.get_winner_total(o,x,t);

        cout<<manager;

        //input invalidation for program re-run by user request
        do {
            cout << "Play again(Y/N)? ";
            cin>>re_run_game;
            cout<<"\n";

            // input invalidation error message
            if(!(re_run_game == "Y" || re_run_game == "y" ||
                 re_run_game == "N" || re_run_game == "n" ))
            {
                cout<<"**INVALID ENTRY!**\n"
                    << "\n";
            }
        }while(!(re_run_game == "Y" || re_run_game == "y" ||
        re_run_game == "N" || re_run_game == "n" ));

    //continues game play loop until user declines
    }while(re_run_game == "Y" || re_run_game == "y");

    // re-run decline exiting message
    cout<<"(-_-)\n"
        <<"≤))≥\n"
        << "_| \\_\n"
        <<"Well...you're no fun!\n"
        <<"\n"
        <<"Program terminated by user...\n";

    return 0;
}

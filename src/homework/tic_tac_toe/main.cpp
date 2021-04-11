#include <iostream>
#include <string>
#include "tic_tac_toe.h"
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

    do
    {
        //creates instance of TikTacToe class
        TikTacToe game_play;

        // initializes variables for user choice and position on board
        string choice;
        int position;

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
            //validation input loop for user position 1-9
            do{
                cout<< game_play.get_player() << " Select position 1-9\n"
                    <<"1|2|3\n"
                    <<"4|5|6\n"
                    <<"7|8|9\n"
                    <<"Enter Position: ";;
                cin>>position;
                cout<<"\n";

                // input invalidation error message
                if(!(position>=1 && position <=9))
                {
                    cout<<"**INVALID ENTRY!**\n"
                        << "\n";
                }
            }while(!(position>=1 && position <=9));

            game_play.mark_board(position);
            game_play.display_board();
            cout<<"\n";

        //loops until game is over not true
        } while(!game_play.game_over());

        cout<<"Game Over! "<< game_play.get_winner()<<"\n"<<"\n";

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

#include <iostream>
#include <string>
#include "tic_tac_toe.h"
using std::string;
using std::cout;
using std::cin;

int main() 
{
    string choice;
    int position;
    TikTacToe game_start;

    cout<<"Select X or O: ";
    cin>>choice;

    game_start.start_game(choice);

    do
    {
        cout<<game_start.get_player()<< " select position from 1-9.\n";
        cin>>position;

        game_start.mark_board(position);
        game_start.display_board();
        cout<<"\n";

    } while(!game_start.game_over());

    cout<<"Game Over! :(";

    return 0;
}
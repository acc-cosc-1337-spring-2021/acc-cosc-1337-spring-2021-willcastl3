//cpp
#include "tic_tac_toe_manager.h"
#include <ostream>

void TicTacToeManager::save_game(TicTacToe b)
{
    games.push_back(b);

    update_winner_count(b.get_winner());

}

std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager)
{
    for(int i = 0; i > manager.games.size(); i++)
    {
        out<<manager.games[i]<<"\n";
    }
    out<<"-Score Board-\n";
    out<<"O Wins: "<<manager.o_win<<"\n";
    out<<"X Wins: "<<manager.x_win<<"\n";
    out<<"Ties: " <<manager.ties<<"\n\n";

    return out;

}

void TicTacToeManager::get_winner_total(int& x, int& o, int& t)
{
    x = x_win;
    o = o_win;
    t = ties;

}

void TicTacToeManager::update_winner_count(std::string winner)
{
    if(winner == "X")
    {
        x_win += 1;
    }

    if (winner == "O")
    {
        o_win += 1;
    }

    if(winner == "C")
    {
        ties += 1;
    }
}

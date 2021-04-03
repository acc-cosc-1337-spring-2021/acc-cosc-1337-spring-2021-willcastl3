#include <string>
#include <vector>
#include <iostream>
#include "tic_tac_toe.h"


bool TikTacToe::game_over()
{
    return check_board_full();
}

void TikTacToe::start_game(std::string first_player)
{
    if(first_player == "X" || first_player =="O"  )
    {
        player = first_player;
        clear_board();
    }
}

void TikTacToe::mark_board(int position)
{
    pegs[position - 1] = player;
    set_next_player();
}

void TikTacToe::display_board() const
{
    for(int i = 0; i < 9; i++)
    {
        std::cout << pegs[i];

        if ((i+1) % 3 == 0)
        {
            std::cout<<"\n";
        }

        else
        {
            std::cout<<" | ";
        }
    }
}

void TikTacToe::set_next_player()
{
    {
        if (player == "O")
            player = "X";
        else
            player = "O";

    }
}

bool TikTacToe::check_board_full()
{
        bool is_full = true;

        for(int i = 0; i < 9; i++)
        {
            if(pegs[i] == " ")
                is_full = false;
        }

        return is_full;
}

void TikTacToe::clear_board()
{
    for (std::string p : pegs)
    {
        p = " ";
    }

}


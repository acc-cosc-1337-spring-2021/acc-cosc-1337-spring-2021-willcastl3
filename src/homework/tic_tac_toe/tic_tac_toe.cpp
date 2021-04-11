#include <string>
#include <iostream>
#include "tic_tac_toe.h"

bool TikTacToe::game_over()
{
    if(check_column_win() || check_row_win() || check_diagonal_win())
    {
        set_winner();
        return true;
    }

    else if (check_board_full())
    {
        winner = "C";
        return true;
    }

    return false;
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
        if (player == "X")
            player = "O";
        else
            player = "X";

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
    for (std::string& p : pegs)
    {
        p = " ";
    }

}

bool TikTacToe::check_column_win() {

    bool win = true;

    for(int i = 0; i<9; i++ )
    {
        if((pegs[0] == "X" && pegs[3]=="X" && pegs[6] == "X") ||
        (pegs[0] == "O" && pegs[3]=="O" && pegs[6] == "O"))
        {
            return win;
        }

        if((pegs[1] == "X" && pegs[4]=="X" && pegs[7] == "X") ||
        (pegs[1] == "O" && pegs[4]=="O" && pegs[7] == "O"))
        {
            return win;
        }

        if((pegs[2] == "X" && pegs[5]=="X" && pegs[8] == "X") ||
        (pegs[2] == "O" && pegs[5]=="O" && pegs[8] == "O"))
        {
            return win;
        }
    }

    return false;
}

bool TikTacToe::check_diagonal_win() {

    bool win = true;

    for(int i = 0; i<9; i++ )
    {
        if((pegs[0] == "X" && pegs[4]=="X" && pegs[8] == "X") ||
        (pegs[0] == "O" && pegs[4]=="O" && pegs[8] == "O"))
        {
            return win;
        }

        if((pegs[6] == "X" && pegs[4]=="X" && pegs[2] == "X") ||
        (pegs[6] == "O" && pegs[4]=="O" && pegs[2] == "O"))
        {
            return win;
        }
    }

    return false;
}

bool TikTacToe::check_row_win() {

    bool win = true;

    for(int i = 0; i<9; i++ )
    {
        if((pegs[0] == "X" && pegs[1]=="X" && pegs[2] == "X") ||
        (pegs[0] == "O" && pegs[1]=="O" && pegs[2] == "O"))
        {
            return win;
        }

        if((pegs[3] == "X" && pegs[4]=="X" && pegs[5] == "X") ||
        (pegs[3] == "O" && pegs[4]=="O" && pegs[5] == "O"))
        {
            return win;
        }

        if((pegs[6] == "X" && pegs[7]=="X" && pegs[8] == "X") ||
        (pegs[6] == "O" && pegs[7]=="O" && pegs[8] == "O"))
        {
            return win;
        }
    }
    return false;
}

void TikTacToe::set_winner() {

    if(player == "X" )
    {
        winner = "O Wins!";

    }else{
     winner = "X Wins!";
    }
}

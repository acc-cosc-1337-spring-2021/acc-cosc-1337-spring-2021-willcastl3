#include <string>
#include <iostream>
#include "tic_tac_toe.h"

bool TicTacToe::game_over()
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

void TicTacToe::start_game(std::string first_player)
{
    if(first_player == "X" || first_player =="O"  )
    {
        player = first_player;
        clear_board();
    }
}

void TicTacToe::mark_board(int position)
{
    pegs[position - 1] = player;
    set_next_player();
}

void TicTacToe::set_next_player()
{
    {
        if (player == "X")
            player = "O";
        else
            player = "X";

    }
}

bool TicTacToe::check_board_full()
{
    bool is_full = true;

    if(pegs.size() == 9)
    {
        for (int i = 0; i < 9; i++)
        {
            if (pegs[i] == " ")
                is_full = false;
        }
    }

    else if(pegs.size() == 16)
    {
        for (int i = 0; i < 16; i++)
        {
            if (pegs[i] == " ")
                is_full = false;
        }
    }

    return is_full;
}

void TicTacToe::clear_board()
{
    for (std::string& p : pegs)
    {
        p = " ";
    }

}

void TicTacToe::set_winner() {

    if(player == "X" )
    {
        winner = "O";

    }else{
     winner = "X";
    }
}

bool TicTacToe::check_column_win() {
    return false;
}

bool TicTacToe::check_row_win() {
    return false;
}

bool TicTacToe::check_diagonal_win() {
    return false;
}


//FRIEND FUNCTIONS
std::ostream& operator<<(std::ostream& out, const TicTacToe& game)
{
    if(game.pegs.size() == 9)
    {
        for(int i = 0; i < 9; i++)
        {
            std::cout << game.pegs[i];
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

    else if(game.pegs.size() == 16)
    {
        for(int i = 0; i < 16; i++)
        {
            std::cout << game.pegs[i];
            if ((i+1) % 4 == 0)
            {
                std::cout<<"\n";
            }
            else
            {
                std::cout<<" | ";
            }
        }
    }
    return out;
}

std::istream& operator>>(std::istream& in, TicTacToe& game)
{
    int position;

    if(game.pegs.size() == 9)
    {
        do {
            std::cout << game.get_player() << " select position 1-9\n"
                      << "1|2|3\n"
                      << "4|5|6\n"
                      << "7|8|9\n"
                      << "Enter Position: ";
            std::cin >> position;

            // input invalidation error message
            if (!(position >= 1 && position <= 9)) {
                std::cout << "**INVALID ENTRY!**\n"
                          << "\n";
            }
        } while (!(position >= 1 && position <= 9));

        game.mark_board(position);
        return in;
    }

    else if(game.pegs.size() == 16)
    {
        do {
            std::cout << game.get_player() << " select position 1-16\n"
                      << "1 |2 |3 |4\n"
                      << "5 |6 |7 |8\n"
                      << "9 |10|11|12\n"
                      << "13|14|15|16\n"
                      << "Enter Position: ";
            std::cin >> position;

            // input invalidation error message
            if (!(position >= 1 && position <= 16)) {
                std::cout << "**INVALID ENTRY!**\n"
                          << "\n";
            }
        } while (!(position >= 1 && position <= 16));

        game.mark_board(position);
        return in;
    }
}


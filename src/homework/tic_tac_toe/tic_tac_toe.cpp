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

    for(int i = 0; i < 9; i++)
    {
        if(pegs[i] == " ")
            is_full = false;
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

bool TicTacToe::check_column_win() {

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

bool TicTacToe::check_diagonal_win() {

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

bool TicTacToe::check_row_win() {

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

void TicTacToe::set_winner() {

    if(player == "X" )
    {
        winner = "O";

    }else{
     winner = "X";
    }
}


//FRIEND FUNCTIONS
std::ostream& operator<<(std::ostream& out, const TicTacToe& game)
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
    std::cout<<"\n";
    return out;
}

std::istream& operator>>(std::istream& in, TicTacToe& game)
{
    int position;

    do{
        std::cout<< game.get_player() << " select position 1-9\n"
            <<"1|2|3\n"
            <<"4|5|6\n"
            <<"7|8|9\n"
            <<"Enter Position: ";;
        std::cin>>position;

        // input invalidation error message
        if(!(position>=1 && position <=9))
        {
            std::cout<<"**INVALID ENTRY!**\n"
                << "\n";
        }
    }while(!(position>=1 && position <=9));

    game.mark_board(position);

    return in;
}
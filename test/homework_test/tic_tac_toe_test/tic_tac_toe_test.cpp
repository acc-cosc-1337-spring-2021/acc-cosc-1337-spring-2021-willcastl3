#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"
#include "memory"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify Player Sets to X 3x3")
{
    TicTacToe3 set_player_to_x;
    set_player_to_x.start_game("X");
    REQUIRE(set_player_to_x.get_player() == "X");
}

TEST_CASE("Verify Player Sets to O 3x3")
{
    TicTacToe3 set_player_to_o;
    set_player_to_o.start_game("O");
    REQUIRE(set_player_to_o.get_player() == "O");
}

TEST_CASE("Verify game ends when board is full, tie game, no winner 3x3")
{
    TicTacToe3 tie_game;
    tie_game.start_game("x");

    tie_game.mark_board(1);//x
    REQUIRE(tie_game.game_over() == false);
    tie_game.mark_board(2);//o
    REQUIRE(tie_game.game_over() == false);
    tie_game.mark_board(3);//x
    REQUIRE(tie_game.game_over() == false);
    tie_game.mark_board(4);//o
    REQUIRE(tie_game.game_over() == false);
    tie_game.mark_board(5);//x
    REQUIRE(tie_game.game_over() == false);
    tie_game.mark_board(7);//o
    REQUIRE(tie_game.game_over() == false);
    tie_game.mark_board(6);//x
    REQUIRE(tie_game.game_over() == false);
    tie_game.mark_board(9);//o
    REQUIRE(tie_game.game_over() == false);
    tie_game.mark_board(8);//x
    REQUIRE(tie_game.game_over() == true);
    REQUIRE(tie_game.get_winner() == "C");
}

TEST_CASE("Verify win by first column 3x3", "X wins first column 3x3")
{
    TicTacToe3 first_column_win;
    first_column_win.start_game("X");

    REQUIRE(first_column_win.game_over() == false);
    first_column_win.mark_board(1);//x
    REQUIRE(first_column_win.game_over() == false);
    first_column_win.mark_board(2);//o
    REQUIRE(first_column_win.game_over() == false);
    first_column_win.mark_board(4);//x
    REQUIRE(first_column_win.game_over() == false);
    first_column_win.mark_board(3);//o
    REQUIRE(first_column_win.game_over() == false);
    first_column_win.mark_board(7);//x
    //x wins
    REQUIRE(first_column_win.game_over() == true);
}

TEST_CASE("Verify win by second column 3x3", "X wins second column")
{
    TicTacToe3 second_column_win;
    second_column_win.start_game("X");

    REQUIRE(second_column_win.game_over() == false);
    second_column_win.mark_board(2);//x
    REQUIRE(second_column_win.game_over() == false);
    second_column_win.mark_board(1);//o
    REQUIRE(second_column_win.game_over() == false);
    second_column_win.mark_board(5);//x
    REQUIRE(second_column_win.game_over() == false);
    second_column_win.mark_board(4);//o
    REQUIRE(second_column_win.game_over() == false);
    second_column_win.mark_board(8);//x
    //x wins
    REQUIRE(second_column_win.game_over() == true);
}

TEST_CASE("Verify win by third column 3x3", "X wins third column")
{
    TicTacToe3 third_column_win;
    third_column_win.start_game("X");

    REQUIRE(third_column_win.game_over() == false);
    third_column_win.mark_board(3);//x
    REQUIRE(third_column_win.game_over() == false);
    third_column_win.mark_board(1);//o
    REQUIRE(third_column_win.game_over() == false);
    third_column_win.mark_board(6);//x
    REQUIRE(third_column_win.game_over() == false);
    third_column_win.mark_board(4);//o
    REQUIRE(third_column_win.game_over() == false);
    third_column_win.mark_board(9);//x
    //x wins
    REQUIRE(third_column_win.game_over() == true);
}

TEST_CASE("Verify diagonal win, left to right 3x3", "X wins diagonally")
{
    TicTacToe3 diagonal_win_leftToright;
    diagonal_win_leftToright.start_game("X");

    REQUIRE(diagonal_win_leftToright.game_over() == false);
    diagonal_win_leftToright.mark_board(1);//x
    REQUIRE(diagonal_win_leftToright.game_over() == false);
    diagonal_win_leftToright.mark_board(2);//o
    REQUIRE(diagonal_win_leftToright.game_over() == false);
    diagonal_win_leftToright.mark_board(5);//x
    REQUIRE(diagonal_win_leftToright.game_over() == false);
    diagonal_win_leftToright.mark_board(4);//o
    REQUIRE(diagonal_win_leftToright.game_over() == false);
    diagonal_win_leftToright.mark_board(9);//x
    //x wins
    REQUIRE(diagonal_win_leftToright.game_over() == true);
}

TEST_CASE("Verify diagonal win, right to left 3x3", "X wins diagonally ")
{
    TicTacToe3 diagonal_win_rightToleft;
    diagonal_win_rightToleft.start_game("X");

    REQUIRE(diagonal_win_rightToleft.game_over() == false);
    diagonal_win_rightToleft.mark_board(3);//x
    REQUIRE(diagonal_win_rightToleft.game_over() == false);
    diagonal_win_rightToleft.mark_board(2);//o
    REQUIRE(diagonal_win_rightToleft.game_over() == false);
    diagonal_win_rightToleft.mark_board(5);//x
    REQUIRE(diagonal_win_rightToleft.game_over() == false);
    diagonal_win_rightToleft.mark_board(4);//o
    REQUIRE(diagonal_win_rightToleft.game_over() == false);
    diagonal_win_rightToleft.mark_board(7);//x
    //x wins
    REQUIRE(diagonal_win_rightToleft.game_over() == true);
}

TEST_CASE("Verify by first row 3x3", "X wins first row")
{
    TicTacToe3 first_row_win;
    first_row_win.start_game("X");

    REQUIRE(first_row_win.game_over() == false);
    first_row_win.mark_board(1);//x
    REQUIRE(first_row_win.game_over() == false);
    first_row_win.mark_board(4);//o
    REQUIRE(first_row_win.game_over() == false);
    first_row_win.mark_board(2);//x
    REQUIRE(first_row_win.game_over() == false);
    first_row_win.mark_board(5);//o
    REQUIRE(first_row_win.game_over() == false);
    first_row_win.mark_board(3);//x
    //x wins
    REQUIRE(first_row_win.game_over() == true);
}

TEST_CASE("Verify by second row 3x3", "X wins second row")
{
    TicTacToe3 second_row_win;
    second_row_win.start_game("X");

    REQUIRE(second_row_win.game_over() == false);
    second_row_win.mark_board(4);//x
    REQUIRE(second_row_win.game_over() == false);
    second_row_win.mark_board(1);//o
    REQUIRE(second_row_win.game_over() == false);
    second_row_win.mark_board(5);//x
    REQUIRE(second_row_win.game_over() == false);
    second_row_win.mark_board(2);//o
    REQUIRE(second_row_win.game_over() == false);
    second_row_win.mark_board(6);//x
    //x wins
    REQUIRE(second_row_win.game_over() == true);
}

TEST_CASE("Verify by third row 3x3", "X wins third row")
{
    TicTacToe3 third_row_win;
    third_row_win.start_game("X");

    REQUIRE(third_row_win.game_over() == false);
    third_row_win.mark_board(7);//x
    REQUIRE(third_row_win.game_over() == false);
    third_row_win.mark_board(4);//o
    REQUIRE(third_row_win.game_over() == false);
    third_row_win.mark_board(8);//x
    REQUIRE(third_row_win.game_over() == false);
    third_row_win.mark_board(5);//o
    REQUIRE(third_row_win.game_over() == false);
    third_row_win.mark_board(9);//x
    //x wins
    REQUIRE(third_row_win.game_over() == true);
}

TEST_CASE("Test case, test get winner class function 3x3")
{

    TicTacToeManager manager;
    unique_ptr<TicTacToe> tie = std::make_unique<TicTacToe3>();
    // Tie 3x3

    tie->start_game("X");
    tie->mark_board(1);//x
    REQUIRE(tie->game_over() == false);
    tie->mark_board(2);//o
    REQUIRE(tie->game_over() == false);
    tie->mark_board(3);//x
    REQUIRE(tie->game_over() == false);
    tie->mark_board(4);//o
    REQUIRE(tie->game_over() == false);
    tie->mark_board(5);//x
    REQUIRE(tie->game_over() == false);
    tie->mark_board(7);//o
    REQUIRE(tie->game_over() == false);
    tie->mark_board(6);//x
    REQUIRE(tie->game_over() == false);
    tie->mark_board(9);//o
    REQUIRE(tie->game_over() == false);
    tie->mark_board(8);//x
    REQUIRE(tie->game_over() == true);
    REQUIRE(tie->get_winner() == "C");
    manager.save_game(tie);

    unique_ptr<TicTacToe> x_wins_third_row = std::make_unique<TicTacToe3>();

    //X Wins Third Row 3x3
    x_wins_third_row->start_game("X");
    REQUIRE(x_wins_third_row->game_over() == false);
    x_wins_third_row->mark_board(7);//x
    REQUIRE(x_wins_third_row->game_over() == false);
    x_wins_third_row->mark_board(4);//o
    REQUIRE(x_wins_third_row->game_over() == false);
    x_wins_third_row->mark_board(8);//x
    REQUIRE(x_wins_third_row->game_over() == false);
    x_wins_third_row->mark_board(5);//o
    REQUIRE(x_wins_third_row->game_over() == false);
    x_wins_third_row->mark_board(9);//x
    //x wins
    REQUIRE(x_wins_third_row->game_over() == true);
    REQUIRE(x_wins_third_row->get_winner() == "X");
    manager.save_game(x_wins_third_row);

    unique_ptr<TicTacToe> o_wins_third_row = std::make_unique<TicTacToe3>();
    // O Wins Third row 3x3
    o_wins_third_row->start_game("O");
    REQUIRE(o_wins_third_row->game_over() == false);
    o_wins_third_row->mark_board(7);//o
    REQUIRE(o_wins_third_row->game_over() == false);
    o_wins_third_row->mark_board(4);//x
    REQUIRE(o_wins_third_row->game_over() == false);
    o_wins_third_row->mark_board(8);//o
    REQUIRE(o_wins_third_row->game_over() == false);
    o_wins_third_row->mark_board(5);//x
    REQUIRE(o_wins_third_row->game_over() == false);
    o_wins_third_row->mark_board(9);//o
    //O wins
    REQUIRE(o_wins_third_row->game_over() == true);
    REQUIRE(o_wins_third_row->get_winner() == "O");
    manager.save_game(o_wins_third_row);

    int x, o, t;
    manager.get_winner_total(o,x,t);
    REQUIRE(x == 1);
    REQUIRE(o == 1);
    REQUIRE(t == 1);
}



// TicTacToe 4 TEST CASES
TEST_CASE("Verify Player Sets to X, 4x4")
{
    TicTacToe4 set_player_to_x;
    set_player_to_x.start_game("X");
    REQUIRE(set_player_to_x.get_player() == "X");
}

TEST_CASE("Verify Player Sets to O, 4x4")
{
    TicTacToe4 set_player_to_o;
    set_player_to_o.start_game("O");
    REQUIRE(set_player_to_o.get_player() == "O");
}

TEST_CASE("Verify game ends when board is full, tie game, no winner 4x4")
{
    TicTacToe4 tie_game;
    tie_game.start_game("X");

    tie_game.mark_board(1);//x
    REQUIRE(tie_game.game_over() == false);
    tie_game.mark_board(2);//o
    REQUIRE(tie_game.game_over() == false);
    tie_game.mark_board(3);//x
    REQUIRE(tie_game.game_over() == false);
    tie_game.mark_board(4);//o
    REQUIRE(tie_game.game_over() == false);
    tie_game.mark_board(5);//x
    REQUIRE(tie_game.game_over() == false);
    tie_game.mark_board(6);//o
    REQUIRE(tie_game.game_over() == false);
    tie_game.mark_board(7);//x
    REQUIRE(tie_game.game_over() == false);
    tie_game.mark_board(8);//o
    REQUIRE(tie_game.game_over() == false);
    tie_game.mark_board(9);//x
    REQUIRE(tie_game.game_over() == false);
    tie_game.mark_board(10);//0
    REQUIRE(tie_game.game_over() == false);
    tie_game.mark_board(11);//x
    REQUIRE(tie_game.game_over() == false);
    tie_game.mark_board(12);//o
    REQUIRE(tie_game.game_over() == false);
    tie_game.mark_board(14);//x
    REQUIRE(tie_game.game_over() == false);
    tie_game.mark_board(13);//o
    REQUIRE(tie_game.game_over() == false);
    tie_game.mark_board(16);//x
    REQUIRE(tie_game.game_over() == false);
    tie_game.mark_board(15);//o
    REQUIRE(tie_game.game_over() == true);
    REQUIRE(tie_game.get_winner() == "C");

}


TEST_CASE("Verify win by first column 4x4", "X wins first column" )
{
    TicTacToe4 first_column_win;
    first_column_win.start_game("X");

    REQUIRE(first_column_win.game_over() == false);
    first_column_win.mark_board(1);//x
    REQUIRE(first_column_win.game_over() == false);
    first_column_win.mark_board(2);//o
    REQUIRE(first_column_win.game_over() == false);
    first_column_win.mark_board(5);//x
    REQUIRE(first_column_win.game_over() == false);
    first_column_win.mark_board(3);//o
    REQUIRE(first_column_win.game_over() == false);
    first_column_win.mark_board(9);//x
    REQUIRE(first_column_win.game_over() == false);
    first_column_win.mark_board(4);//o
    REQUIRE(first_column_win.game_over() == false);
    first_column_win.mark_board(13);//x
    //x wins
    REQUIRE(first_column_win.game_over() == true);
}

TEST_CASE("Verify win by second column 4x4", "X wins second column")
{
    TicTacToe4 second_column_win;
    second_column_win.start_game("X");

    REQUIRE(second_column_win.game_over() == false);
    second_column_win.mark_board(2);//x
    REQUIRE(second_column_win.game_over() == false);
    second_column_win.mark_board(1);//o
    REQUIRE(second_column_win.game_over() == false);
    second_column_win.mark_board(6);//x
    REQUIRE(second_column_win.game_over() == false);
    second_column_win.mark_board(5);//o
    REQUIRE(second_column_win.game_over() == false);
    second_column_win.mark_board(10);//x
    REQUIRE(second_column_win.game_over() == false);
    second_column_win.mark_board(9);//o
    REQUIRE(second_column_win.game_over() == false);
    second_column_win.mark_board(14);//x
    //x wins
    REQUIRE(second_column_win.game_over() == true);
    REQUIRE(second_column_win.get_winner() == "X");
}

TEST_CASE("Verify win by third column 4x4", "X wins third column")
{
    TicTacToe4 third_column_win;
    third_column_win.start_game("X");

    REQUIRE(third_column_win.game_over() == false);
    third_column_win.mark_board(3);//x
    REQUIRE(third_column_win.game_over() == false);
    third_column_win.mark_board(2);//o
    REQUIRE(third_column_win.game_over() == false);
    third_column_win.mark_board(7);//x
    REQUIRE(third_column_win.game_over() == false);
    third_column_win.mark_board(6);//o
    REQUIRE(third_column_win.game_over() == false);
    third_column_win.mark_board(11);//x
    REQUIRE(third_column_win.game_over() == false);
    third_column_win.mark_board(10);//o
    REQUIRE(third_column_win.game_over() == false);
    third_column_win.mark_board(15);//x
    //x wins
    REQUIRE(third_column_win.game_over() == true);
    REQUIRE(third_column_win.get_winner() == "X");
}

TEST_CASE("Verify win by fourth column 4x4", "X wins fourth column")
{
    TicTacToe4 fourth_column_win;
    fourth_column_win.start_game("X");

    REQUIRE(fourth_column_win.game_over() == false);
    fourth_column_win.mark_board(4);//x
    REQUIRE(fourth_column_win.game_over() == false);
    fourth_column_win.mark_board(2);//o
    REQUIRE(fourth_column_win.game_over() == false);
    fourth_column_win.mark_board(8);//x
    REQUIRE(fourth_column_win.game_over() == false);
    fourth_column_win.mark_board(6);//o
    REQUIRE(fourth_column_win.game_over() == false);
    fourth_column_win.mark_board(12);//x
    REQUIRE(fourth_column_win.game_over() == false);
    fourth_column_win.mark_board(10);//o
    REQUIRE(fourth_column_win.game_over() == false);
    fourth_column_win.mark_board(16);//x
    //x wins
    REQUIRE(fourth_column_win.game_over() == true);
    REQUIRE(fourth_column_win.get_winner() == "X");
}

TEST_CASE("Verify diagonal win, left to right 4x4", "X wins diagonally")
{
    TicTacToe4 diagonal_win_leftToright;
    diagonal_win_leftToright.start_game("X");

    REQUIRE(diagonal_win_leftToright.game_over() == false);
    diagonal_win_leftToright.mark_board(1);//x
    REQUIRE(diagonal_win_leftToright.game_over() == false);
    diagonal_win_leftToright.mark_board(2);//o
    REQUIRE(diagonal_win_leftToright.game_over() == false);
    diagonal_win_leftToright.mark_board(6);//x
    REQUIRE(diagonal_win_leftToright.game_over() == false);
    diagonal_win_leftToright.mark_board(4);//o
    REQUIRE(diagonal_win_leftToright.game_over() == false);
    diagonal_win_leftToright.mark_board(11);//x
    REQUIRE(diagonal_win_leftToright.game_over() == false);
    diagonal_win_leftToright.mark_board(9);//o
    REQUIRE(diagonal_win_leftToright.game_over() == false);
    diagonal_win_leftToright.mark_board(16);//x
    //x wins
    REQUIRE(diagonal_win_leftToright.game_over() == true);
    REQUIRE(diagonal_win_leftToright.get_winner() == "X");
}

TEST_CASE("Verify diagonal win, right to left 4x4", "X wins diagonally")
{
    TicTacToe4 diagonal_win_rightToleft;
    diagonal_win_rightToleft.start_game("X");

    REQUIRE(diagonal_win_rightToleft.game_over() == false);
    diagonal_win_rightToleft.mark_board(4);//x
    REQUIRE(diagonal_win_rightToleft.game_over() == false);
    diagonal_win_rightToleft.mark_board(2);//o
    REQUIRE(diagonal_win_rightToleft.game_over() == false);
    diagonal_win_rightToleft.mark_board(7);//x
    REQUIRE(diagonal_win_rightToleft.game_over() == false);
    diagonal_win_rightToleft.mark_board(6);//o
    REQUIRE(diagonal_win_rightToleft.game_over() == false);
    diagonal_win_rightToleft.mark_board(10);//x
    REQUIRE(diagonal_win_rightToleft.game_over() == false);
    diagonal_win_rightToleft.mark_board(1);//o
    REQUIRE(diagonal_win_rightToleft.game_over() == false);
    diagonal_win_rightToleft.mark_board(13);//x
    //x wins
    REQUIRE(diagonal_win_rightToleft.game_over() == true);
    REQUIRE(diagonal_win_rightToleft.get_winner() == "X");
}

TEST_CASE("Verify by first row 4x4", "X wins first row")
{
    TicTacToe4 first_row_win;
    first_row_win.start_game("X");

    REQUIRE(first_row_win.game_over() == false);
    first_row_win.mark_board(1);//x
    REQUIRE(first_row_win.game_over() == false);
    first_row_win.mark_board(5);//o
    REQUIRE(first_row_win.game_over() == false);
    first_row_win.mark_board(2);//x
    REQUIRE(first_row_win.game_over() == false);
    first_row_win.mark_board(6);//o
    REQUIRE(first_row_win.game_over() == false);
    first_row_win.mark_board(3);//x
    REQUIRE(first_row_win.game_over() == false);
    first_row_win.mark_board(7);//o
    REQUIRE(first_row_win.game_over() == false);
    first_row_win.mark_board(4);//x
    //x wins
    REQUIRE(first_row_win.game_over() == true);
    REQUIRE(first_row_win.get_winner() == "X");
}

TEST_CASE("Verify by second row 4x4 ", "X wins second row")
{
    TicTacToe4 second_row_win;
    second_row_win.start_game("X");

    REQUIRE(second_row_win.game_over() == false);
    second_row_win.mark_board(5);//x
    REQUIRE(second_row_win.game_over() == false);
    second_row_win.mark_board(1);//o
    REQUIRE(second_row_win.game_over() == false);
    second_row_win.mark_board(6);//x
    REQUIRE(second_row_win.game_over() == false);
    second_row_win.mark_board(2);//o
    REQUIRE(second_row_win.game_over() == false);
    second_row_win.mark_board(7);//x
    REQUIRE(second_row_win.game_over() == false);
    second_row_win.mark_board(3);//o
    REQUIRE(second_row_win.game_over() == false);
    second_row_win.mark_board(8);//x
    //x wins
    REQUIRE(second_row_win.game_over() == true);
    REQUIRE(second_row_win.get_winner() == "X");

}

TEST_CASE("Verify by third row 4x4", "X wins third row")
{
    TicTacToe4 third_row_win;
    third_row_win.start_game("X");

    REQUIRE(third_row_win.game_over() == false);
    third_row_win.mark_board(9);//x
    REQUIRE(third_row_win.game_over() == false);
    third_row_win.mark_board(1);//o
    REQUIRE(third_row_win.game_over() == false);
    third_row_win.mark_board(10);//x
    REQUIRE(third_row_win.game_over() == false);
    third_row_win.mark_board(2);//o
    REQUIRE(third_row_win.game_over() == false);
    third_row_win.mark_board(11);//x
    REQUIRE(third_row_win.game_over() == false);
    third_row_win.mark_board(3);//o
    REQUIRE(third_row_win.game_over() == false);
    third_row_win.mark_board(12);//x
    //x wins
    REQUIRE(third_row_win.game_over() == true);
    REQUIRE(third_row_win.get_winner() == "X");
}

TEST_CASE("Verify by fourth row 4x4", "X wins fourth row")
{
    TicTacToe4 fourth_row_win;
    fourth_row_win.start_game("X");

    REQUIRE(fourth_row_win.game_over() == false);
    fourth_row_win.mark_board(13);//x
    REQUIRE(fourth_row_win.game_over() == false);
    fourth_row_win.mark_board(1);//o
    REQUIRE(fourth_row_win.game_over() == false);
    fourth_row_win.mark_board(14);//x
    REQUIRE(fourth_row_win.game_over() == false);
    fourth_row_win.mark_board(2);//o
    REQUIRE(fourth_row_win.game_over() == false);
    fourth_row_win.mark_board(15);//x
    REQUIRE(fourth_row_win.game_over() == false);
    fourth_row_win.mark_board(3);//o
    REQUIRE(fourth_row_win.game_over() == false);
    fourth_row_win.mark_board(16);//x
    //x wins
    REQUIRE(fourth_row_win.game_over() == true);
    REQUIRE(fourth_row_win.get_winner() == "X");

}

TEST_CASE("Test case, test get winner class function 4x4")
{
    TicTacToeManager manager;
    unique_ptr<TicTacToe> tie = std::make_unique<TicTacToe4>();
    // Tie using 4x4
    tie->start_game("X");
    tie->mark_board(1);//x
    REQUIRE(tie->game_over() == false);
    tie->mark_board(2);//o
    REQUIRE(tie->game_over() == false);
    tie->mark_board(3);//x
    REQUIRE(tie->game_over() == false);
    tie->mark_board(4);//o
    REQUIRE(tie->game_over() == false);
    tie->mark_board(5);//x
    REQUIRE(tie->game_over() == false);
    tie->mark_board(6);//o
    REQUIRE(tie->game_over() == false);
    tie->mark_board(7);//x
    REQUIRE(tie->game_over() == false);
    tie->mark_board(8);//o
    REQUIRE(tie->game_over() == false);
    tie->mark_board(9);//x
    REQUIRE(tie->game_over() == false);
    tie->mark_board(10);//0
    REQUIRE(tie->game_over() == false);
    tie->mark_board(11);//x
    REQUIRE(tie->game_over() == false);
    tie->mark_board(12);//o
    REQUIRE(tie->game_over() == false);
    tie->mark_board(14);//x
    REQUIRE(tie->game_over() == false);
    tie->mark_board(13);//o
    REQUIRE(tie->game_over() == false);
    tie->mark_board(16);//x
    REQUIRE(tie->game_over() == false);
    tie->mark_board(15);//o
    REQUIRE(tie->game_over() == true);

    REQUIRE(tie->get_winner() == "C");
    manager.save_game(tie);

    unique_ptr<TicTacToe> x_wins_first_column = std::make_unique<TicTacToe4>();
    //X Wins first column using 4x4
    x_wins_first_column->start_game("X");

    REQUIRE(x_wins_first_column->game_over() == false);
    x_wins_first_column->mark_board(1);//x
    REQUIRE(x_wins_first_column->game_over() == false);
    x_wins_first_column->mark_board(2);//o
    REQUIRE(x_wins_first_column->game_over() == false);
    x_wins_first_column->mark_board(5);//x
    REQUIRE(x_wins_first_column->game_over() == false);
    x_wins_first_column->mark_board(3);//o
    REQUIRE(x_wins_first_column->game_over() == false);
    x_wins_first_column->mark_board(9);//x
    REQUIRE(x_wins_first_column->game_over() == false);
    x_wins_first_column->mark_board(4);//o
    REQUIRE(x_wins_first_column->game_over() == false);
    x_wins_first_column->mark_board(13);//x
    //x wins
    REQUIRE(x_wins_first_column->game_over() == true);
    REQUIRE(x_wins_first_column->get_winner() == "X");
    manager.save_game(x_wins_first_column);

    //O Wins first column using 4x4
    unique_ptr<TicTacToe> o_wins_first_column = std::make_unique<TicTacToe4>();

    o_wins_first_column->start_game("O");
    REQUIRE(o_wins_first_column->game_over() == false);
    o_wins_first_column->mark_board(1);//o
    REQUIRE(o_wins_first_column->game_over() == false);
    o_wins_first_column->mark_board(2);//x
    REQUIRE(o_wins_first_column->game_over() == false);
    o_wins_first_column->mark_board(5);//o
    REQUIRE(o_wins_first_column->game_over() == false);
    o_wins_first_column->mark_board(3);//x
    REQUIRE(o_wins_first_column->game_over() == false);
    o_wins_first_column->mark_board(9);//o
    REQUIRE(o_wins_first_column->game_over() == false);
    o_wins_first_column->mark_board(4);//x
    REQUIRE(o_wins_first_column->game_over() == false);
    o_wins_first_column->mark_board(13);//o
    //o wins
    REQUIRE(o_wins_first_column->game_over() == true);
    REQUIRE(o_wins_first_column->get_winner() == "O");

    manager.save_game(o_wins_first_column);

    int o,x,t;
    manager.get_winner_total(o,x,t);
    REQUIRE(x == 1);
    REQUIRE(o == 1);
    REQUIRE(t == 1);
}
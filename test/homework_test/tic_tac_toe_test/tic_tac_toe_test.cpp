#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify Player Sets to X")
{
    TicTacToe set_player_to_x;
    set_player_to_x.start_game("X");
    REQUIRE(set_player_to_x.get_player() == "X");
}

TEST_CASE("Verify Player Sets to O")
{
    TicTacToe set_player_to_o;
    set_player_to_o.start_game("O");
    REQUIRE(set_player_to_o.get_player() == "O");
}

TEST_CASE("Verify game ends when board is full, tie game, no winner")
{
    TicTacToe tie_game;
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

TEST_CASE("Verify win by first column", "X wins first column")
{
    TicTacToe first_column_win;
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

TEST_CASE("Verify win by second column", "X wins second column")
{
    TicTacToe second_column_win;
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

TEST_CASE("Verify win by third column", "X wins third column")
{
    TicTacToe third_column_win;
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

TEST_CASE("Verify diagonal win, left to right", "X wins diagonally")
{
    TicTacToe diagonal_win_leftToright;
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

TEST_CASE("Verify diagonal win, right to left", "X wins diagonally ")
{
    TicTacToe diagonal_win_rightToleft;
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

TEST_CASE("Verify by first row", "X wins first row")
{
    TicTacToe first_row_win;
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

TEST_CASE("Verify by second row", "X wins second row")
{
    TicTacToe second_row_win;
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

TEST_CASE("Verify by third row", "X wins third row")
{
    TicTacToe third_row_win;
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

TEST_CASE("Test case, test get winner class function")
{
    TicTacToeManager manager;
    TicTacToe game;

    // Tie
    game.start_game("X");
    game.mark_board(1);//x
    REQUIRE(game.game_over() == false);
    game.mark_board(2);//o
    REQUIRE(game.game_over() == false);
    game.mark_board(3);//x
    REQUIRE(game.game_over() == false);
    game.mark_board(4);//o
    REQUIRE(game.game_over() == false);
    game.mark_board(5);//x
    REQUIRE(game.game_over() == false);
    game.mark_board(7);//o
    REQUIRE(game.game_over() == false);
    game.mark_board(6);//x
    REQUIRE(game.game_over() == false);
    game.mark_board(9);//o
    REQUIRE(game.game_over() == false);
    game.mark_board(8);//x
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "C");
    manager.save_game(game);

    //X Wins Third Row
    game.start_game("X");
    REQUIRE(game.game_over() == false);
    game.mark_board(7);//x
    REQUIRE(game.game_over() == false);
    game.mark_board(4);//o
    REQUIRE(game.game_over() == false);
    game.mark_board(8);//x
    REQUIRE(game.game_over() == false);
    game.mark_board(5);//o
    REQUIRE(game.game_over() == false);
    game.mark_board(9);//x
    //x wins
    REQUIRE(game.game_over() == true);
    manager.save_game(game);

    // O Wins Third row
    game.start_game("O");
    REQUIRE(game.game_over() == false);
    game.mark_board(7);//o
    REQUIRE(game.game_over() == false);
    game.mark_board(4);//x
    REQUIRE(game.game_over() == false);
    game.mark_board(8);//o
    REQUIRE(game.game_over() == false);
    game.mark_board(5);//x
    REQUIRE(game.game_over() == false);
    game.mark_board(9);//o
    //O wins
    REQUIRE(game.game_over() == true);
    manager.save_game(game);

    int x, o, t;
    manager.get_winner_total(o,x,t);
    REQUIRE(x == 1);
    REQUIRE(o == 1);
    REQUIRE(t == 1);

}
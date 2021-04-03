#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify that all 9 slots on board have been filled")
{
    TikTacToe game_test;
    game_test.start_game("X");
    game_test.mark_board(1);
    game_test.mark_board(2);
    game_test.mark_board(3);
    game_test.mark_board(4);
    game_test.mark_board(5);
    game_test.mark_board(6);
    game_test.mark_board(7);
    game_test.mark_board(8);
    game_test.mark_board(9);

}
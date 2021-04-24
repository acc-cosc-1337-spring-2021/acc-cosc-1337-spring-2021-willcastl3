#ifndef TIC_TAC_TOE_MANAGER
#define TIC_TAC_TOE_MANAGER
#include "tic_tac_toe.h"
#include <vector>
#include <string>
#include "memory"
using std::unique_ptr;

class TicTacToeManager
{
    //FRIEND FUNCTIONS
    friend std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager);

public:
    void save_game(unique_ptr<TicTacToe>& b);
    void get_winner_total(int& o, int& x, int& t);

private:
    std::vector<unique_ptr<TicTacToe>> games;
    int x_win = 0;
    int o_win = 0;
    int ties = 0;
    void update_winner_count(std::string winner);
};

#endif
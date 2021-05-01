#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H
#include "tic_tac_toe.h"
#include "tic_tac_toe_data.h"
#include <vector>
#include <string>
#include <memory>

using std::unique_ptr;

class TicTacToeManager
{

//FRIEND FUNCTIONS
    friend std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager);

public:
    TicTacToeManager() = default;
    TicTacToeManager(TicTacToeData data);
    void save_game(unique_ptr<TicTacToe>& game);
    void get_winner_total(int& o, int& x, int& t);
    ~TicTacToeManager();

private:
    std::vector<unique_ptr<TicTacToe>> games;
    TicTacToeData data;
    int x_win = 0;
    int o_win = 0;
    int ties = 0;
    void update_winner_count(std::string winner);
};

#endif
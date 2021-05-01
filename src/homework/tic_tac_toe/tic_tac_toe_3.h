//h
#ifndef TIC_TAC_TOE_3_H
#define TIC_TAC_TOE_3_H
#include "tic_tac_toe.h"

class TicTacToe3 : public TicTacToe
{
public:
    TicTacToe3() : TicTacToe(3){}
    TicTacToe3(std::vector<std::string> p, const std::string w) : TicTacToe(p,w){};
private:
     bool check_column_win() override;
     bool check_row_win() override;
     bool check_diagonal_win() override;

};
#endif
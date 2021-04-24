#ifndef TIC_TAC_TOE
#define TIC_TAC_TOE

#include <string>
#include <vector>
#include <ostream>

class TicTacToe
{
    //FRIEND FUNCTIONS
    friend std::ostream& operator<<(std::ostream& out, const TicTacToe& game);
    friend std::istream& operator>>(std::istream& in, TicTacToe& game);

public:
    TicTacToe()= default;
    explicit TicTacToe(int size) : pegs(size *  size," "){}
    bool game_over();
    void start_game(std::string first_player);
    void mark_board(int position);
    std::string get_player()const{return player;}
    std::string get_winner()const{return winner;}

protected:
    std::vector <std::string> pegs;
    virtual bool check_column_win();
    virtual bool check_row_win();
    virtual bool check_diagonal_win();

private:
    void set_winner();
    void set_next_player();
    bool check_board_full();
    void clear_board();
    std::string player;
    std::string winner;

};

#endif

#include "game/chess.hpp"

// Utiliser algorithm, des lock_guard (en cas de prog concurrentielle), std::array, des interfaces
// Classes abstraites!	


int main()
{
	chess::init_board();
	chess::print_board();
	chess::play_turn();
	chess::print_board();

	return 0;
}
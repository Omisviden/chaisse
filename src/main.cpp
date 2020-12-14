#include <iostream>
#include "game/chess.hpp"

// Utiliser algorithm, des lock_guard (en cas de prog concurrentielle), std::array, des interfaces
// Classes abstraites!	

using namespace std;

int main()
{
	cout << "Hello World" << endl;
	chess::print_board();
	return 0;
}
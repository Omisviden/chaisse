#include "Piece.hpp"
#include <array>
#include <iostream>

namespace chess
{
	enum Color : bool; // Black = 0, White = 1.

	void init_legal_moves(); // Put pieces in their initial state.
	void init_board(); //
	
	void move_piece(Piece &p, int x, int y); // Move a piece to another square.
	void print_board(); // Print the board state to the console.

};

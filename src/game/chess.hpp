#include <array>
#include <iostream>
#include <memory>

#include "Piece.hpp"

namespace chess
{
	enum class Color : bool; // Black = 0, White = 1.

	void init_board(); //
	void print_board(); // Print the board state to the console.
	
	void move_piece(std::unique_ptr<Piece>& piece, int col, int row); // Move a piece to another square.

	void play_turn(); // Play mockup turn to test move_piece();
};

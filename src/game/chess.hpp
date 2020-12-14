#pragma once
#include "Piece.hpp"
#include <array>
#include <iostream>

namespace chess
{
	enum Color : bool; // Black = 0, White = 1.
	enum Pieces : char; // WPawn = 'P', BPawn = 'p', WBishop = 'B', etc.

	char chessboard[8][8];

	void init_chessboard(); // Put pieces in their initial state.
	void move_piece(Piece &p, int x, int y); // Move a piece to another square.
	void print_board(); // Print the board state to the console.
};

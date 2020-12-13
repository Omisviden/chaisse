#pragma once

#include "Piece.cpp"
#include <array>

namespace chess
{
	enum class Color : int { White=0, Black=1 };
	Piece* chessboard[8][8];
	
	void init_chessboard();
	void move_piece(int x, int y);
}
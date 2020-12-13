#include <iostream>
#include "chess.hpp"
#include "Piece.cpp"
#include "Pawn.hpp"

namespace chess
{
	// What do we need in a game of chess? 
	// - Ways to move pieces
	// - Ways to check the validity of a moved piece
	// - Ways to make pieces disappear (captures and promotion)

	enum Color : bool { Black=false, White = true };
	Piece* chessboard[8][8];

	void init_chessboard()
	{
		
	}

	void move_piece(int x, int y)
	{
		std::cout << "Haha";
	}
}
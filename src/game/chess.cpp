#include "chess.hpp"
#include "Piece.hpp"
#include "Pawn.hpp"

#include <iostream>
#include <string>

/// <summary>
/// Single purpose of this namespace: Managing the board state.
/// Dependencies: A game logic module
/// </summary>

namespace chess
{
	// What do we need in a game of chess? 
	// - Ways to move pieces
	// - Ways to make pieces disappear (captures and promotion)
	enum Color : bool { Black = true, White = false };

	Piece* chessboard[8][8];

	void init_board()
	{
		// bool <=> int, 0 = false & 1 = true so we can use the loop index as our color directly.
		// 0 = White; 1 = Black
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				chessboard[i][j] = nullptr;
			}
		}

		for (int color = 0; color < 2; color++)
		{
			for (int i = 0; i < 8; i++)
			{
				if (color == Black)
				{
					Pawn pawn(i, 6, Black);
					chessboard[i][6] = &pawn;
				}
				else
				{
					Pawn pawn(i, 6, White);
					chessboard[i][1] = &pawn;
				}
			}
		}

		// Knights, bishops and rooks.

		//chessboard[1][0] = WKnight;
		//chessboard[6][0] = WKnight;
		//chessboard[5][0] = WBishop;
		//chessboard[2][0] = WBishop;
		//chessboard[0][0] = WRook;
		//chessboard[7][0] = WRook;

		//chessboard[1][7] = BKnight;
		//chessboard[6][7] = BKnight;
		//chessboard[5][7] = BBishop;
		//chessboard[2][7] = BBishop;
		//chessboard[0][7] = BRook;
		//chessboard[7][7] = BRook;

		//// Queens and kings.
		//chessboard[3][0] = WQueen;
		//chessboard[4][0] = WKing;

		//chessboard[3][7] = BQueen;
		//chessboard[4][7] = BKing; // Burger king!!!
	}

	void print_board()
	{
		std::cout << "============" << std::endl;
		for (int i = 7; i > -1; i--)
		{
			std::cout << "||";
			for (int j = 0; j < 8; j++)
			{
				if (chessboard[j][i] != nullptr)
					std::cout << chessboard[j][i]->get_repr();
				else
					std::cout << " ";
			}
			std::cout << "||" << std::endl;
		}
		std::cout << "============" << std::endl;
	}

	void move_piece(Piece& piece, int x, int y)
	{
		piece.set_col(x);
		piece.set_row(y);
		throw std::string("ERREUR: Pas encore implémenté");
	}
}
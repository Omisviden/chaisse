#include "chess.hpp"
#include <iostream>
#include "Piece.hpp"
#include "Pawn.hpp"

/// <summary>
/// Single purpose of this namespace: Managing the board state.
/// Dependencies: A game logic module
/// </summary>

namespace chess
{
	// What do we need in a game of chess? 
	// - Ways to move pieces
	// - Ways to make pieces disappear (captures and promotion)
	enum Color : bool { Black = false, White = true };
	enum Pieces : char
	{
		WPawn = 'P',
		WKnight = 'N',
		WBishop = 'B',
		WRook = 'R',
		WQueen = 'Q',
		WKing = 'K',

		BPawn = 'p',
		BKnight = 'n',
		BBishop = 'b',
		BRook = 'r',
		BQueen = 'q',
		BKing = 'k', // Burger king haha
	};

	void init_chessboard()
	{
		// bool <=> int, 0 = false & 1 = true so we can use the loop index as our color directly.
		// 0 = Black; 1 = White
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				chessboard[i][j] = ' ';
			}
		}

		for (int color = 0; color < 2; color++)
		{
			for (int i = 0; i < 8; i++)
			{
				if (color == Black)
				{
					chessboard[i][6] = BPawn;
					Pawn p(i, 6, Black);
				}
				else
				{
					chessboard[i][1] = WPawn;
					Pawn p(i, 1, White);
				}
			}
		}

		// Knights, bishops and rooks.
		chessboard[1][0] = WKnight;
		chessboard[6][0] = WKnight;
		chessboard[5][0] = WBishop;
		chessboard[2][0] = WBishop;
		chessboard[0][0] = WRook;
		chessboard[7][0] = WRook;

		chessboard[1][7] = BKnight;
		chessboard[6][7] = BKnight;
		chessboard[5][7] = BBishop;
		chessboard[2][7] = BBishop;
		chessboard[0][7] = BRook;
		chessboard[7][7] = BRook;

		// Queens and kings.
		chessboard[3][0] = WQueen;
		chessboard[4][0] = WKing;

		chessboard[3][7] = BQueen;
		chessboard[4][7] = BKing; // Burger king!!!

	}

	void print_board()
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 7; j > -1; j--)
			{
				std::cout << chessboard[i][j];
			}
		}
	}

	void move_piece(Piece& piece, int x, int y)
	{
		std::cout << "Haha";
	}
}
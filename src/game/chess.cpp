#include <iostream>
#include <string>
#include <array>
#include <memory>

#include "chess.hpp"
#include "Piece.hpp"
#include "Pawn.hpp"
#include "Queen.hpp"

#include "toolbox.hpp"

/// <summary>
/// Single purpose of this namespace: Managing the board state.
/// Dependencies: A game logic module
/// </summary>


namespace chess
{
	// What do we need in a game of chess? 
	// - Ways to move pieces
	// - Ways to make pieces disappear (captures and promotion)


	enum class Color : bool { Black = true, White = false };

	toolbox::Array2D<std::unique_ptr<Piece>, 8, 8> chessboard;
	

	// Initializes the chessboard.
	void init_board() 	
	{
		// bool <=> int, 0 = false & 1 = true so we can use the loop index as our color directly.
		// 0 = White; 1 = Black

		for (int color = 0; color < 2; color++)
		{
			for (int i = 0; i < 8; i++)
			{
				// Since make_unique builds an object and wraps it in a unique pointer, both the Pawn and
				// the unique_ptr depend entirely on the chessboard: their lifetime is tied to it.
				if (color)
					chessboard[i][6] = std::make_unique<Pawn>(i, 6, (bool)Color::Black);
				else
					chessboard[i][1] = std::make_unique<Pawn>(i, 6, (bool)Color::White);
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
		chessboard[3][0] = std::make_unique<Queen>(3, 0, (bool)Color::White);
		//chessboard[4][0] = WKing;

		chessboard[3][7] = std::make_unique<Queen>(3, 7, (bool)Color::Black);
		//chessboard[4][7] = BKing; // Burger king!!!
	}

	void print_board()
	{
		std::cout << "============" << std::endl;
		for (int i = 0; i < 8; i++)
		{
			std::cout << "||";
			for (int j = 0; j < 8; j++)
			{
				if (chessboard[j][i] != nullptr)
					std::cout << chessboard[j][i].get()->get_repr();
				else
					std::cout << " ";
			}
			std::cout << "||" << std::endl;
		}
		std::cout << "============" << std::endl;
	}

	void move_piece(std::unique_ptr<Piece>& piece, int col, int row)
	{
		// This is supposed to move the shared_ptr from the old location to the new one, overriding any other piece pointers on it.
		// Since the other piece pointer is a unique_ptr, it *should* bring the counter to zero and kill the associated piece.

		int old_col = piece.get()->get_col();

		int old_row = piece.get()->get_row();

		chessboard[col][row] = std::move(piece);
		chessboard[col][row].get()->set_col(col);
		chessboard[col][row].get()->set_row(row);
		chessboard[old_col][old_row] = nullptr;
	}

	void play_turn()
	{
		move_piece(chessboard[3][0], 4, 3);
	}
}
#include "Pawn.hpp"
#include <vector>

// It doesn't really make sense to have an empty constructor since pieces always have to be assigned coordinates and a color.
Pawn::Pawn(int x, int y, int color)
{
	this->m_row = x;
	this->m_col = y;
	this->m_color = color;

	//TODO: Find a way to add diagonal (capture) moves only when a piece can be captured
	// ^ This will probably be done in chess.cpp as the pawn needs information from the chessboard
	this->m_legal_moves = {{0, 1}}; // {col, row}
}

std::vector<std::array<int, 2>> Pawn::get_legal_moves() { return m_legal_moves; }
void Pawn::set_legal_moves(std::vector<std::array<int, 2>> l_m) { m_legal_moves = l_m; }

int Pawn::get_col() { return m_col; }
void Pawn::set_col(int y) { m_col = y; }

int Pawn::get_row() { return m_row; }
void Pawn::set_row(int x) { m_row = x; }
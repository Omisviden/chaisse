#include "Pawn.hpp"
#include <vector>

// It doesn't really make sense to have an empty constructor since pieces always have to be assigned coordinates and a color.
Pawn::Pawn(int x, int y, bool color) : _row(x), _col(y)
{
	if (color) // Black = 1; White = 0
		_repr = 'p';
	else
		_repr = 'P';
}

std::vector<std::array<int, 2>> Pawn::get_legal_moves() { return _legal_moves; }
void Pawn::set_legal_moves(std::vector<std::array<int, 2>> l_m) { _legal_moves = l_m; }

int Pawn::get_col() { return _col; }
void Pawn::set_col(int y) { _col = y; }

int Pawn::get_row() { return _row; }
void Pawn::set_row(int x) { _row = x; }

char Pawn::get_repr() { return _repr; }
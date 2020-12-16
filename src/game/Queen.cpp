#include "Queen.hpp"
#include <vector>

// It doesn't really make sense to have an empty constructor since pieces always have to be assigned coordinates and a color.
Queen::Queen(int x, int y, bool color) : _row(x), _col(y)
{
	if (color) // Black = 1; White = 0
		_repr = 'm';
	else
		_repr = 'M';
}

std::vector<std::array<int, 2>> Queen::get_legal_moves() { return _legal_moves; }
void Queen::set_legal_moves(std::vector<std::array<int, 2>> l_m) { _legal_moves = l_m; }

int Queen::get_col() { return _col; }
void Queen::set_col(int y) { _col = y; }

int Queen::get_row() { return _row; }
void Queen::set_row(int x) { _row = x; }

char Queen::get_repr() { return _repr; }
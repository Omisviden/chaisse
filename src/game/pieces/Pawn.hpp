#include "Piece.hpp"

class Pawn : public Piece
{
public:
	Pawn(int x, int y, bool color); // White = false, Black = true

	std::vector<std::array<int, 2>> get_legal_moves();
	void set_legal_moves(std::vector<std::array<int, 2>>);

	int get_col();
	void set_col(int);

	int get_row();
	void set_row(int);

	char get_repr();

protected:
	std::vector<std::array<int, 2>> _legal_moves;
	int _row, _col;
	char _repr;
};
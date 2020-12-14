#include "Piece.hpp"

class Pawn : public Piece
{
public:
	Pawn(int x, int y, int color);

	std::vector<std::array<int, 2>> get_legal_moves();
	void set_legal_moves(std::vector<std::array<int, 2>>);

	int get_col();
	void set_col(int);

	int get_row();
	void set_row(int);

protected:
	std::vector<std::array<int, 2>> m_legal_moves;
	int m_row, m_col, m_color;
};
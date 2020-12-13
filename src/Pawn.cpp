#include "Piece.cpp"

class Pawn : public Piece
{
public:
	int get_row() = 0;
	int set_row() = 0;
	int get_col() = 0;
	int set_col() = 0;

private:
	int m_row, m_col, m_color;
};
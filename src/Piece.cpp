#pragma once

class Piece
{
public:
	virtual int get_row() = 0;
	virtual int set_row() = 0;
	virtual int get_col() = 0;
	virtual int set_col() = 0;

protected:
	int m_x, m_y, m_color;
};

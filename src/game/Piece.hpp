#pragma once
#include <vector>
#include <array>
/// <summary>
/// Single purpose of this class: Provide an interface for piece control.
/// </summary>
class Piece
{
public:
	virtual std::vector<std::array<int, 2>> get_legal_moves() = 0;
	virtual void set_legal_moves(std::vector<std::array<int, 2>>) = 0;

	virtual int get_row() = 0;
	virtual void set_row(int) = 0;

	virtual int get_col() = 0;
	virtual void set_col(int) = 0;

protected:
	int m_x, m_y, m_color;
	std::vector<std::array<int, 2>> m_legal_moves;
};
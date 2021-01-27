#pragma once
#include <vector>
#include <array>
/// <summary>
/// The Piece header file provides an interface for piece control.
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

	virtual char get_repr() = 0;

protected:
	int _row, _col;
	std::vector<std::array<int, 2>> m_legal_moves;
	char _repr;
};
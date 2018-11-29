#include <iostream>

#include "tetris.h"



Tetris::Block::Block(std::string name) {
	const char blockName = name[0];
	const int rotationNum = name[1] - '0';

	switch (blockName) {
	case 'A':
	{
		char blockA[4][4] = {
		{'.', '.', '.', '.'},
		{'A', 'A', 'A', 'A'},
		{'.', '.', '.', '.'},
		{'.', '.', '.', '.'}
		};
		rotation(rotationNum);
	}
	break;
	case 'B':
	{
		char blockA[4][4] = {
		{'.', '.', '.', '.'},
		{'B', 'B', 'B', '.'},
		{'.', 'B', '.', '.'},
		{'.', '.', '.', '.'}
		};
		rotation(rotationNum);
	}
	break;
	case 'C':
	{
		char blockA[4][4] = {
		{'.', '.', '.', '.'},
		{'.', 'C', 'C', '.'},
		{'.', 'C', 'C', '.'},
		{'.', '.', '.', '.'}
		};
		rotation(rotationNum);
	}
	break;
	case 'D':
	{
		char blockA[4][4] = {
		{'.', '.', '.', '.'},
		{'D', 'D', '.', '.'},
		{'.', 'D', 'D', '.'},
		{'.', '.', '.', '.'}
		};
		rotation(rotationNum);
	}
	break;
	case 'E':
	{
		char blockA[4][4] = {
		{'.', '.', '.', '.'},
		{'.', 'E', 'E', '.'},
		{'E', 'E', '.', '.'},
		{'.', '.', '.', '.'}
		};
		rotation(rotationNum);
	}
	break;
	case 'F':
	{
		char blockA[4][4] = {
		{'.', '.', '.', '.'},
		{'F', 'F', 'F', '.'},
		{'.', '.', 'F', '.'},
		{'.', '.', '.', '.'}
		};
		rotation(rotationNum);
	}
	break;
	case 'G':
	{
		char blockA[4][4] = {
		{'.', '.', '.', '.'},
		{'.', '.', 'G', '.'},
		{'G', 'G', 'G', '.'},
		{'.', '.', '.', '.'}
		};
		rotation(rotationNum);
	}
	break;
	default :
		break;
	}
}

Tetris::Tetris() {
	for (int i = 0; i < 13; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (i == 0 || i == 12 || j == 0 || j == 8) {
				field[i][j] = 'X'; // 가장자리 표시
			}
			else {
				field[i][j] = '.';
			}
		}
	}

	blockMap["A0"] = Block("A0");
	blockMap["A1"] = Block("A1");
	blockMap["A2"] = Block("A2");
	blockMap["A3"] = Block("A3");
	blockMap["B0"] = Block("B0");
	blockMap["B1"] = Block("B1");
	blockMap["B2"] = Block("B2");
	blockMap["B3"] = Block("B3");
	blockMap["C0"] = Block("C0");
	blockMap["C1"] = Block("C1");
	blockMap["C2"] = Block("C2");
	blockMap["C3"] = Block("C3");
	blockMap["D0"] = Block("D0");
	blockMap["D1"] = Block("D1");
	blockMap["D2"] = Block("D2");
	blockMap["D3"] = Block("D3");
	blockMap["E0"] = Block("E0");
	blockMap["E1"] = Block("E1");
	blockMap["E2"] = Block("E2");
	blockMap["E3"] = Block("E3");
	blockMap["F0"] = Block("F0");
	blockMap["F1"] = Block("F1");
	blockMap["F2"] = Block("F2");
	blockMap["F3"] = Block("F3");
	blockMap["G0"] = Block("G0");
	blockMap["G1"] = Block("G1");
	blockMap["G2"] = Block("G2");
	blockMap["G3"] = Block("G3");

}



int main() {



	return 0;

}
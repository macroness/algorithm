#include <iostream>
#include <assert.h>

#include "tetris.h"

Tetris::Block::Block() : block(), leftX(0), leftY(0), currentX(0), currentY(0), h(0) {
}

Tetris::Block::Block(const std::string name) {
	const char blockName = name[0];
	const int rotationNum = name[1] - '0';

	switch (blockName) {
	case 'A':
	{
		char srcBlock[4][4] = {
		{'.', '.', '.', '.'},
		{'A', 'A', 'A', 'A'},
		{'.', '.', '.', '.'},
		{'.', '.', '.', '.'}
		};
		memcpy(block, srcBlock, sizeof(block));
		rotation(rotationNum);
	}
	break;
	case 'B':
	{
		char srcBlock[4][4] = {
		{'.', '.', '.', '.'},
		{'B', 'B', 'B', '.'},
		{'.', 'B', '.', '.'},
		{'.', '.', '.', '.'}
		};
		memcpy(block, srcBlock, sizeof(block));
		rotation(rotationNum);
	}
	break;
	case 'C':
	{
		char srcBlock[4][4] = {
		{'.', '.', '.', '.'},
		{'.', 'C', 'C', '.'},
		{'.', 'C', 'C', '.'},
		{'.', '.', '.', '.'}
		};
		memcpy(block, srcBlock, sizeof(block));
		rotation(rotationNum);
	}
	break;
	case 'D':
	{
		char srcBlock[4][4] = {
		{'.', '.', '.', '.'},
		{'D', 'D', '.', '.'},
		{'.', 'D', 'D', '.'},
		{'.', '.', '.', '.'}
		};
		memcpy(block, srcBlock, sizeof(block));
		rotation(rotationNum);
	}
	break;
	case 'E':
	{
		char srcBlock[4][4] = {
		{'.', '.', '.', '.'},
		{'.', 'E', 'E', '.'},
		{'E', 'E', '.', '.'},
		{'.', '.', '.', '.'}
		};
		memcpy(block, srcBlock, sizeof(block));
		rotation(rotationNum);
	}
	break;
	case 'F':
	{
		char srcBlock[4][4] = {
		{'.', '.', '.', '.'},
		{'F', 'F', 'F', '.'},
		{'.', '.', 'F', '.'},
		{'.', '.', '.', '.'}
		};
		memcpy(block, srcBlock, sizeof(block));
		rotation(rotationNum);
	}
	break;
	case 'G':
	{
		char srcBlock[4][4] = {
		{'.', '.', '.', '.'},
		{'.', '.', 'G', '.'},
		{'G', 'G', 'G', '.'},
		{'.', '.', '.', '.'}
		};
		memcpy(block, srcBlock, sizeof(block));
		rotation(rotationNum);
	}
	break;
	default :
		break;
	}

	setPosition();
}

static void swapAB(char& a, char& b) {
	char tmp = a;
	a = b;
	b = tmp;
}

void Tetris::Block::rotation(int n) {
	for (int r = 0; r < n; ++r) {
		// ��ġ��� �����
		for (int i = 1; i < 4; ++i) {
			for (int j = 0; j < i; ++j) {
				swapAB(block[i][j], block[j][i]);
			}
		}

		// ���Ʒ� �ٲٱ�
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 4; ++j) {
				swapAB(block[i][j], block[3 - i][j]);
			}
		}
	}
}

void Tetris::Block::setPosition() {
	// ���� ���� �����ִ� ����ġ ã��
	bool loopEnd = false;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (block[j][i] != '.') {
				leftX = j;
				leftY = i;
				loopEnd = true;
				break;
			}
		}
		if (loopEnd) {
			break;
		}
	}

	// ������ �Ǵ� ���� ��ġ���� ��ĭ ���� �� �׷��� �Ǵ��� Ȯ��
	loopEnd = false;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (block[i][j] != '.') {
				h = leftX - i;
				loopEnd = true;
				break;
			}
		}
		if (loopEnd) {
			break;
		}
	}
}

Tetris::Tetris() {
	for (int i = 0; i < 14; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (i == 0 || i == 13 || j == 0 || j == 9) {
				field[i][j] = 'X'; // �����ڸ� ǥ��
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

Tetris::~Tetris() {

}

bool Tetris::checkConflict(const Block& b) {
	// bX,Y : block�� �׸� ���� ��ǥ
	// fX,Y : block�� �׷��� field�� ��ǥ
	for (int bX = b.leftX - b.h, fX = b.currentX - b.h; bX < 4 && fX < 14; ++bX, ++fX) {
		for (int bY = b.leftY, fY = b.currentY; bY < 4 && fY < 10; ++bY, ++fY) {
			if (b.block[bX][bY] != '.' && field[fX][fY] != '.') {
				return true;
			}
		}
	}
	return false;
}

void Tetris::situateBlockInField(Block* b) {
	// bX,Y : block�� �׸� ���� ��ǥ
	// fX,Y : block�� �׷��� field�� ��ǥ
	for (int bX = b->leftX - b->h, fX = b->currentX - b->h; bX < 4 && fX < 14; ++bX, ++fX) {
		for (int bY = b->leftY, fY = b->currentY; bY < 4 && fY < 10; ++bY, ++fY) {
			if (b->block[bX][bY] != '.') {
				field[fX][fY] = b->block[bX][bY];
				// ������ left�� �׸����ִٸ� ���� field�ڸ��� block�� �����Ѵ�.(currnetX,Y)
				if (bX == b->leftX && bY == b->leftY) {
					b->currentX = fX;
					b->currentY = fY;
				}
			}
		}
	}
}

void Tetris::setBlock(Block* b) {

	if (!checkConflict(*b)) {
		// bX,Y : block�� �׸� ���� ��ǥ
		// fX,Y : block�� �׷��� field�� ��ǥ
		for (int bX = b->leftX - b->h, fX = b->currentX - b->h; bX < 4 && fX < 14; ++bX, ++fX) {
			for (int bY = b->leftY, fY = b->currentY; bY < 4 && fY < 10; ++bY, ++fY) {
				if (b->block[bX][bY] != '.') {
					field[fX][fY] = b->block[bX][bY];
					// ������ left�� �׸����ִٸ� ���� field�ڸ��� block�� �����Ѵ�.(currnetX,Y)
					if (bX == b->leftX && bY == b->leftY) {
						b->currentX = fX;
						b->currentY = fY;
					}
				}
			} 
		}
	}
	else {
		std::cout << "�߸��� �Է��Դϴ�.\n";
		assert(false);
	}
}

void Tetris::printField() {

	for (int i = 1; i < 13; ++i) {
		for (int j = 1; j < 9; ++j) {
			std::cout << field[i][j];
		}
		std::cout << "\n";
	}

}

void Tetris::downBlock(Block* b) {
	b->currentX++;

	while (!checkConflict(*b)) {
		b->currentX++;
	}

	b->currentX--;
	situateBlockInField(b);
}

void Tetris::pushBlock(const std::string blockInfo) {

	std::size_t beginPos = blockInfo.find_first_of('(');
	while (beginPos != std::string::npos) {
		const std::string blockName = blockInfo.substr(beginPos + 1, 2);
		const int firstPos = std::stoi(blockInfo.substr(beginPos + 4, 1));
		Block b(blockMap[blockName]);

		// ���̸�ŭ ������ ��ǥ�� �������� y�� �־������.
		b.currentX = b.h + 1;
		b.currentY = firstPos;

		// ó���� ���������� ���� �׸��� ���� ������ �׸��°� �ƴϱ� ������ �׸��� �� field�� �����ִٰ� down�ϱ��� ���� ����.
		char tmpField[14][10] = { '0' };
		memcpy(tmpField, field, sizeof(field));

		setBlock(&b);


		std::cout << "================================\n";
		std::cout << "blockName = " << blockName << "\n";
		std::cout << "position  = " << firstPos << "\n";

		printField();

		std::cout << "--------------------------------\n";

		memcpy(field, tmpField, sizeof(field));
		downBlock(&b);

		printField();
		std::cout << "================================\n";

		beginPos = blockInfo.find_first_of('(', beginPos + 1);
	}

}

int main() {

	Tetris tt;

	tt.pushBlock("(D3,5)");
	return 0;

}
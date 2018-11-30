#include <map>
#include <string>

class Tetris {
public:
	Tetris();

	~Tetris();

	void pushBlock(const std::string blockInfo);

private:
	class Block {
	public:
		Block();
		Block(const std::string name); // name : 초기 블럭 종류와 시계방향 회전수  ex) A0 ~A3, B0 ~ B3

	private:
		void rotation(int n);
		void setPosition();

	public:
		char block[4][4];
		int leftX; // 왼쪽에서 가장 높은 위치 x좌표 (이 x,y값이 블럭을 그릴때의 기준이됨)
		int leftY; // 왼쪽에서 가장 높은 위치 y좌표
		int h; // 왼쪽좌표와 높이 차이
		int currentX; // 블럭의 left 칸이 그려진 field의 x좌표
		int currentY; // 블럭의 left 칸이 그려진 field의 y좌표
	};

private:
	void setBlock(Block* b, const int y);
	void printField();
	void downBlock(Block* b);
	bool checkConflict(const Block& b);

private:
	char field[14][10];
	std::map<std::string, Block> blockMap;
};
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
		Block(const std::string name); // name : �ʱ� �� ������ �ð���� ȸ����  ex) A0 ~A3, B0 ~ B3

	private:
		void rotation(int n);
		void setPosition();

	public:
		char block[4][4];
		int leftX; // ���ʿ��� ���� ���� ��ġ x��ǥ (�� x,y���� ���� �׸����� �����̵�)
		int leftY; // ���ʿ��� ���� ���� ��ġ y��ǥ
		int h; // ������ǥ�� ���� ����
		int currentX; // ���� left ĭ�� �׷��� field�� x��ǥ
		int currentY; // ���� left ĭ�� �׷��� field�� y��ǥ
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
#include <map>
#include <string>

class Tetris {
public:
	Tetris();

	~Tetris();


private:
	class Block {
	public:
		Block() {};
		Block(std::string name); // name : �ʱ� �� ������ �ð���� ȸ����  ex) A0 ~A3, B0 ~ B3

	private:
		void rotation(int n);
		void setPosition();
	public:
		char block[4][4];
		int leftX; // ���ʿ��� ���� ���� ��ġ x��ǥ
		int leftY; // ���ʿ��� ���� ���� ��ġ y��ǥ
		int h; // ������ǥ�� ���� ����
	};



private:
	char field[13][9];
	std::map<std::string, Block> blockMap;
};
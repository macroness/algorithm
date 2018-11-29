

class Tetris {
public:
	Tetris();

	~Tetris();


private:
	class Block {
	public:
		Block();
		
		void init(int n); // n : �ʱ� ���� �ð���� ȸ���� (0~3)

	private:
		void rotation(int n);
	public:
		char block[4][4];
		int leftX; // ���ʿ��� ���� ���� ��ġ x��ǥ
		int leftY; // ���ʿ��� ���� ���� ��ġ y��ǥ
		int h; // ������ǥ�� ���� ����
	};



private:
	char field[13][9];

};
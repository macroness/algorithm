

class Tetris {
public:
	Tetris();

	~Tetris();


private:
	class Block {
	public:
		Block();
		
		void init(int n); // n : 초기 블럭의 시계방향 회전수 (0~3)

	private:
		void rotation(int n);
	public:
		char block[4][4];
		int leftX; // 왼쪽에서 가장 높은 위치 x좌표
		int leftY; // 왼쪽에서 가장 높은 위치 y좌표
		int h; // 왼쪽좌표와 높이 차이
	};



private:
	char field[13][9];

};
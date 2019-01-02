#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct A {
	int x;
	int y;

	A operator+(const A& rhs) {
		A a;
		a.x = x + rhs.x;
		a.y = y + rhs.y;
		return a;
	}

	bool operator==(const A& rhs) {
		if (x == rhs.x && y == rhs.y) {
			return true;
		}
		return false;
	}
};

bool findCoor(const int i, const int j) {

}

static vector<A> obel;
static vector<A> clue;
int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		A a;
		cin >> a.x >> a.y;
		obel.push_back(a);
	}

	for (int i = 0; i < n; ++i) {
		A a;
		cin >> a.x >> a.y;
		clue.push_back(a);
	}

	A pre;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			
		}
	}


	return 0;
}

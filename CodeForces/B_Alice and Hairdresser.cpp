#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
	map<int, int> shortHair;
	int n, m, p;
	cin >> n >> m >> p;
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		if (t <= p) {
			shortHair[i + 1] = t;
		}
	}

	int count = 0;
	map<int, int>::const_iterator it = shortHair.begin();
	if (it == shortHair.end()) {
		count = 1;
	}
	else {
		int prev;
		prev = it->first;
		if (prev != 1) {
			count++;
		}
		it++;
		for (; it != shortHair.end(); ++it) {
			if (prev != it->first - 1) {
				count++;
			}
			prev = it->first;
		}
		if (shortHair.find(prev)->first != n) {
			count++;
		}
	}

	shortHair[0] = 1;
	shortHair[n + 1] = 1;

	for (int i = 0; i < m; ++i) {
		int t;
		cin >> t;
		if (t == 0) {
			cout << count << "\n";
			continue;
		}

		int x, l;
		cin >> x >> l;

		map<int, int>::iterator tempIt = shortHair.find(x);
		if (tempIt != shortHair.end()) {
			tempIt->second += l;
			if (tempIt->second > p) {
				map<int, int>::iterator prevIt = tempIt;
				prevIt--;
				map<int, int>::iterator nextIt = tempIt;
				nextIt++;


				if (prevIt->first == x - 1 && nextIt->first == x + 1) {
					count++;
				}
				else if (prevIt->first != x - 1 && nextIt->first != x + 1) {
					count--;
				}

				shortHair.erase(x);
			}
		}
	}
}

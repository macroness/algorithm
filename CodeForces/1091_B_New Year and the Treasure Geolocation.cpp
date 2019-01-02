#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	set<pair<int,int>> obels;

	for (int i = 0; i < n; ++i) {
		pair<int,int> a;
		cin >> a.first >> a.second;
		obels.insert(a);
	}

	vector<pair<int,int>> clues;
	for (int i = 0; i < n; ++i) {
		pair<int,int> a;
		cin >> a.first >> a.second;
		clues.push_back(a);
	}

	pair<int,int> result;
	for (auto obel : obels) {
		result.first = obel.first + clues[0].first;
		result.second = obel.second + clues[0].second;

		bool found = true;
		for (int i = 0; i < n; ++i) {
			if (!obels.count({ result.first - clues[i].first, result.second - clues[i].second })) {
				found = false;
				break;
			}
		}

		if (found) {
			break;
		}
	}

	cout << result.first << " " << result.second;

	return 0;
}

#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct A {
	int idx;
	int l;
	int r;
};
int main() {

	int q = 0;

	cin >> q;
	int size = 0;
	map<int, A> m;
	vector<pair<int, int> > v;
	int curIdx = 0;

	v.push_back(make_pair(0, 0));

	for (int i = 0; i < q; ++i) {
		char req = 0;
		int id = 0;
		cin >> req >> id;

		if (req == 'L') {
			curIdx++;
			m[id].idx = curIdx;
			m[id].l = 0;
			m[id].r = size;
			v.push_back(make_pair(v[size].first + 1, v[size].second));
			size++;
		}
		else if (req == 'R') {
			curIdx++;
			m[id].idx = curIdx;
			m[id].l = size;
			m[id].r = 0;
			v.push_back(make_pair(v[size].first, v[size].second + 1));
			size++;
		}
		else { // '?'
			int l, r;
			map<int, A>::const_iterator it = m.find(id);
			l = it->second.l + (v[curIdx].first - v[it->second.idx].first);
			r = it->second.r + (v[curIdx].second - v[it->second.idx].second);
			if (l < r) {
				cout << l << "\n";
			}
			else {
				cout << r << "\n";
			}
		}
	}
	return 0;
}

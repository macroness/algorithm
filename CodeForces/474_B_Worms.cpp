#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

void getPos(const vector<int>& v, const int l, const int u, const int x) {

	const int m = int((l + u) / 2);

	if (v[m] >= x and v[m - 1] < x) {
		cout << m << "\n";
		return;
	}


	if (v[m] > x) {
		return getPos(v, l, m - 1, x);
	}
	else {
		return getPos(v, m + 1, u, x);
	}
}

int main() {

	int n;
	cin >> n;
	vector<int> listA;
	listA.push_back(0);
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		listA.push_back(a);
	}
	int mm;
	cin >> mm;
	vector<int> listB;
	for (int i = 0; i < mm; ++i) {
		int a;
		cin >> a;
		listB.push_back(a);
	}
	for (int i = 1; i < n + 1; ++i) {
		listA[i] += listA[i - 1];
	}

	for (int i = 0; i < mm; ++i) {
		getPos(listA, 1, n, listB[i]);
	}

	return 0;
}
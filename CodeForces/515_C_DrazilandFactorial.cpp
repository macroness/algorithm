#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


int main() {

	int n;

	cin >> n;

	string a;
	vector<int> x;

	cin >> a;

	for (int i = 0; i < n; ++i) {
		if (a[i] == '0' || a[i] == '1') {
			continue;
		}
		else if (a[i] == '4') {
			x.push_back(2);
			x.push_back(2);
			x.push_back(3);
		}
		else if (a[i] == '6') {
			x.push_back(3);
			x.push_back(5);
		}
		else if (a[i] == '8') {
			x.push_back(2);
			x.push_back(2);
			x.push_back(2);
			x.push_back(7);
		}
		else if (a[i] == '9') {
			x.push_back(2);
			x.push_back(3);
			x.push_back(3);
			x.push_back(7);
		}
		else{
			x.push_back(a[i] - 48);
		}
	}

	sort(x.rbegin(), x.rend());

	for (vector<int>::const_iterator it = x.begin(); it != x.end(); ++it) {
		cout << *it;
	}

	return 0;
}
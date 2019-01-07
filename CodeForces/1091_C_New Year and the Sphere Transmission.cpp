#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<long long> v;

	for (int i = 2; i*i <= n; ++i) {
		if (n % i == 0) {
			v.push_back(i);
			if (i*i != n) {
				v.push_back(n / i);
			}
		}
	}
	v.push_back(1);
	v.push_back(n);

	vector<long long> resV;
	for (auto it : v) {
		const long long x = n - it + 1;
		resV.push_back(((x + 1)*((x - 1) / it + 1)) / 2);
	}
	sort(resV.begin(), resV.end());

	for (auto it : resV) {
		cout << it << " ";
	}

	return 0;
}

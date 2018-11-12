#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<long long> v;

int main() {

	long long n;
	cin >> n;
	v.push_back(2);
	long long count = 0;

	bool checkPrime = true;
	for (int i = 2; i <= sqrt(n); ++i) {
		if (n % i == 0) {
			checkPrime = false;
			break;
		}
	}

	if (checkPrime) {
		cout << "1";
		return 0;
	}

	while (n) {

		if (n % 2 == 0) {
			count += n / 2;
			break;
		}

		bool check = true;
		for (vector<long long>::const_iterator it = v.begin(); it != v.end(); ++it) {
			if (n % *it == 0) {
				n -= *it;
				count++;
				check = false;
				break;
			}
		}

		if (check == false) {
			continue;
		}

		for (int i = *v.rbegin() + 1; i <= 100000; ++i) {

			// check prime
			check = true;
			for (int j = 2; j <= sqrt(i); ++j) {
				if (i % j == 0) {
					check = false;
					break;
				}
			}

			if (check) {
				v.push_back(i);
				if (n % i == 0) {
					n -= i;
					count++;
					break;
				}
			}
		}
	}

	cout << count;

	return 0;
}

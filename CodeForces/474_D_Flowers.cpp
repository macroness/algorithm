#include <iostream>

using namespace std;

const int mod = 1000000007;
const int maxx = 100001;

void setArr(long long a[], const int& k) {

	// 아무것도 없는 경우의 수에 r또는 w를 붙일 수 있으므로 초항은 1로한다
	a[0] = 1;
	// 각 꽃의 개수마다 경우의 수 계산
	for (int i = 1; i < maxx; ++i) {
		a[i] = a[i - 1];
		if (i >= k) {
			a[i] = (a[i] + a[i - k]) % mod;
		}
	}

	// 1 ~ i 개 경우의 수 합 계산
	for (int i = 2; i < maxx; ++i) {
		a[i] = (a[i - 1] + a[i]) % mod;
	}
}

int main() {

	int t, k;

	cin >> t >> k;

	long long summ[maxx] = { 0 };

	setArr(summ, k);

	// 0개의 경우 경우의 수가 0이므로 0으로 바꾼다.
	summ[0] = 0;

	for (int i = 0; i < t; ++i) {
		int a, b;
		cin >> a >> b;
		// 나머지한 값이므로 음수가 될수도 있다 이를위해 mod를 더햇다가 다시 나머지를 구한다.
		cout << (summ[b] - summ[a - 1] + mod) % mod << "\n";
	}

	return 0;
}
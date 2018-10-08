#include <iostream>

using namespace std;

const int mod = 1000000007;
const int maxx = 100001;

void setArr(long long a[], const int& k) {

	// �ƹ��͵� ���� ����� ���� r�Ǵ� w�� ���� �� �����Ƿ� ������ 1���Ѵ�
	a[0] = 1;
	// �� ���� �������� ����� �� ���
	for (int i = 1; i < maxx; ++i) {
		a[i] = a[i - 1];
		if (i >= k) {
			a[i] = (a[i] + a[i - k]) % mod;
		}
	}

	// 1 ~ i �� ����� �� �� ���
	for (int i = 2; i < maxx; ++i) {
		a[i] = (a[i - 1] + a[i]) % mod;
	}
}

int main() {

	int t, k;

	cin >> t >> k;

	long long summ[maxx] = { 0 };

	setArr(summ, k);

	// 0���� ��� ����� ���� 0�̹Ƿ� 0���� �ٲ۴�.
	summ[0] = 0;

	for (int i = 0; i < t; ++i) {
		int a, b;
		cin >> a >> b;
		// �������� ���̹Ƿ� ������ �ɼ��� �ִ� �̸����� mod�� ���޴ٰ� �ٽ� �������� ���Ѵ�.
		cout << (summ[b] - summ[a - 1] + mod) % mod << "\n";
	}

	return 0;
}
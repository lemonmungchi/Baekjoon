#include <iostream>

using namespace std;

int combination(int n, int k) {
	if (k > n - k) k = n - k;  // 계산량을 줄이기 위해 k를 더 작은 값으로 설정
	long long result = 1;
	for (int i = 0; i < k; i++) {
		result *= (n - i);
		result /= (i + 1);
	}
	return result;
}

int main()
{
	int t;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n, m;
		cin >> n >> m;
		cout << combination(m, n) << endl;
	}
}
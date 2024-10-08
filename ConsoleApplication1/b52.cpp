#include <iostream>

using namespace std;

int main()
{
	int n, k;

	cin >> n >> k;

	if (k > n - k) {
		k = n - k;  // nCk == nC(n-k), 계산량 줄이기 위해 k를 더 작은 값으로 설정
	}

	int a = 1, b = 1;

	for (int i = 0; i < k; i++)
	{
		a *= (n - i);
		b *= (k - i);
	}

	cout << a / b << endl;
}
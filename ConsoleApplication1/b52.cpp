#include <iostream>

using namespace std;

int main()
{
	int n, k;

	cin >> n >> k;

	if (k > n - k) {
		k = n - k;  // nCk == nC(n-k), ��귮 ���̱� ���� k�� �� ���� ������ ����
	}

	int a = 1, b = 1;

	for (int i = 0; i < k; i++)
	{
		a *= (n - i);
		b *= (k - i);
	}

	cout << a / b << endl;
}
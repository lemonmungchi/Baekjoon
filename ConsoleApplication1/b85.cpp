#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

typedef vector<vector<long long>> Matrix;

//��� ���� �Լ�
Matrix multiply(const Matrix& a, const Matrix& b)
{
	//���� ����� ������ �Լ�
	Matrix result(2, vector<long long>(2, 0));
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % MOD;
			}
		}
	}

	return result;
}

//��� �ŵ����� �Լ�
Matrix matrixPower(Matrix a, long long n) {
	Matrix result = { {1, 0}, {0, 1} }; // ���� ���
	while (n > 0) {
		if (n % 2 == 1) {
			result = multiply(result, a);
		}
		a = multiply(a, a);
		n /= 2;
	}
	return result;
}

int main()
{
	long long n;
	cin >> n;

	if (n == 0) {
		cout << 0 << endl;
		return 0;
	}

	// �Ǻ���ġ �ʱ� ���
	Matrix a = { {1, 1}, {1, 0} };

	//n��°������ �ǳ볪ġ ���
	Matrix result = matrixPower(a, n - 1);
	
	cout << result[0][0] << "\n";

	return 0;
}
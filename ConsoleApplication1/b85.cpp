#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

typedef vector<vector<long long>> Matrix;

//행렬 곱셈 함수
Matrix multiply(const Matrix& a, const Matrix& b)
{
	//곱셈 결과를 저장할 함수
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

//행렬 거듭제곱 함수
Matrix matrixPower(Matrix a, long long n) {
	Matrix result = { {1, 0}, {0, 1} }; // 단위 행렬
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

	// 피보나치 초기 행렬
	Matrix a = { {1, 1}, {1, 0} };

	//n번째까지의 피노나치 계산
	Matrix result = matrixPower(a, n - 1);
	
	cout << result[0][0] << "\n";

	return 0;
}
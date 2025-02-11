#include <iostream>

#define MOD 1000000000

using namespace std;

int dp[101][10] = { 0 };  //길이 / 자릿수
int main()
{
	int n;
	cin >> n;
	long answer = 0;

	for (int j = 1; j < 10; j++)
	{
		dp[1][j] = 1;		//초기값 설정
	}

	for (int i = 2; i <=n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0) dp[i][j] = dp[i - 1][j + 1];
			else if (j == 9) dp[i][j] = dp[i - 1][j - 1];
			else dp[i][j] = (dp[i - 1][j + 1]+dp[i - 1][j - 1])%MOD;
		}
	}

	for (int j = 0; j < 10; j++)
	{
		answer = (answer + dp[n][j]) % MOD;;
	}

	cout << answer << endl;

	return 0;
}
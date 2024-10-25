#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> cost(n, vector<int>(3));
	vector<vector<int>> dp(n, vector<int>(3));

	//RGB입력받기
	for (int i = 0; i < n; i++)
	{
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}

	// 첫 번째 집 초기화
	dp[0][0] = cost[0][0];
	dp[0][1] = cost[0][1];
	dp[0][2] = cost[0][2];

	//미리 모든 경우의수 계산
	for (int i = 1; i < n; i++)
	{
		dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
		dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
		dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2];
	}

	int result = min({ dp[n - 1][0], dp[n - 1][1], dp[n - 1][2] });
	cout << result << endl;

	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int>dp(n + 1);

	dp[1] = 0;

	for (int i = 2; i <= n; i++)
	{
		//우선 1빼보기
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0)
		{
			//1뺐을때와 2로 나누었을때 비교
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}
		if (i % 3 == 0)
		{
			//1뺐을때와 3로 나누었을때 비교
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
	}

	cout << dp[n];
}

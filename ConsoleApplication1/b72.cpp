#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> triangle(n, vector<int>(n, 0));


	for (int i = 0; i < n; i++)
	{
		for (int j =0; j<=i; j++)
		{
			cin >> triangle[i][j];
		}
		
	}
	
	vector<vector<int>> dp(n, vector<int>(n, 0));

	dp[0][0] = triangle[0][0];

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			//가장 왼쪽
			if (j == 0)
			{
				dp[i][j] = dp[i - 1][j] + triangle[i][j];
			}
			else if (j == i)	//가장 오른쪽
			{
				dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
			}
			else      //가운데
			{
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
			}
		}
	}

	int result = 0;
	for (int i = 0; i < n; i++)
	{
		result = max(dp[n - 1][i], result);
	}

	cout << result << "\n";
}
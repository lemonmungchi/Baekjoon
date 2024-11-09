#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;

	cin >> n;

	vector<int> v(n);
	vector<int> dp(n,1);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int answer = 1;

	
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			//기준값보다 작은게 몇개인지 센다.
			if (v[i] > v[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		answer = max(answer, dp[i]);
	}

	cout << answer << "\n";

	return 0;
}
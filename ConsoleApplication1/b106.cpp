#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> wine(n + 1, 0);
	vector<int> dp(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		cin >> wine[i];
	}
	//초기값 설정
	dp[1] = wine[1];
	if (n > 1) dp[2] = wine[1] + wine[2];
	if (n > 2) dp[3] = max({ wine[1] + wine[2], wine[1] + wine[3], wine[2] + wine[3] });
	//점화식 3가지 중에 제일 큰걸로
	for (int i = 4; i <= n; i++) {
		dp[i] = max({ dp[i - 1], dp[i - 2] + wine[i], dp[i - 3] + wine[i - 1] + wine[i] });
	}

	cout << dp[n] << "\n";
	return 0;
}
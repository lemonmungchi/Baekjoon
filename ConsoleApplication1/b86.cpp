#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> v(n+1, 0);
	vector<int> sum(n+1, 0);

	// 배열 입력 및 누적 합 계산
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		sum[i] = sum[i - 1] + v[i];
	}

	
	for (int q = 0; q < m; q++) {
		int i, j;
		cin >> i >> j;
		cout << sum[j] - sum[i - 1] << "\n";
	}
	
	return 0;
}
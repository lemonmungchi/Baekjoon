#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k; 

	vector<int> v(n, 0);

	// 배열 입력 및 누적 합 계산
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int sum = 0;
	for (int i = 0; i < k; i++)
	{
		sum += v[i];
	}

	int max_sum = sum;

	//슬라이딩 윈도우
	for (int i = k; i < n; i++)
	{
		sum += v[i] - v[i - k];
		max_sum = max(max_sum, sum);
	}

	cout << max_sum << "\n";

	return 0;
}
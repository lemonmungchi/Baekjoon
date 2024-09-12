#include "iostream"

using namespace std;

int main()
{
	int n, sum, answer;

	cin >> n;

	for (int i = 1; i < n; i++)
	{
		int s = i;
		sum = 0;
		while (s > 0)
		{
			//자리수의 합과 그 수 더하기
			sum += s % 10;
			s /= 10;
		}
		if ((sum + i) == n) {
			answer = i;
			break;
		}
	}

	cout << answer << endl;

	return 0;
}
#include "iostream"
#include "algorithm"

using namespace std;

int main()
{
	int n;
	int max_x = -10000, max_y = -10000, min_x = 10000, min_y = 10000;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		max_x = max(x, max_x);
		min_x = min(min_x, x);
		max_y = max(y, max_y);
		min_y = min(min_y, y);
	}

	long long sum = (max_x - min_x) * (max_y - min_y);

	cout << sum << endl;

	return 0;
}
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n;

	cin >> n;

	queue<int> q;

	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}

	while (q.size() != 1)
	{
		int x;
		q.pop();
		x = q.front();
		q.pop();
		q.push(x);
	}

	cout << q.front() << endl;

	return 0;
}
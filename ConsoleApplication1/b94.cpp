#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 100001;

vector<int> v(MAX, 0);

int BFS(int start, int end)
{
	queue<int> q;

	q.push(start);
	v[start] = 1;

	while (!q.empty())
	{
		int curx = q.front();
		q.pop();

		if (curx == end) return v[end] - 1;

		for (int nextx : {curx - 1, curx + 1, 2 * curx})
		{
			//범위검사
			if (nextx >= 0 && nextx < MAX && v[nextx] == 0)
			{
				v[nextx] = v[curx] + 1;
				q.push(nextx);
			}
		}
	}

	return -1;
}


int main()
{
	int n, k;
	cin >> n >> k;


	cout << BFS(n, k) << "\n";

	return 0;
	
}
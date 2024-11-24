#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int bfs(int l, int startX, int startY, int endX, int endY)
{
	vector<vector<int>> visited(l, vector<int>(l, 0));
	queue<pair<int, int>> q;
	q.push({ startX, startY });
	visited[startX][startY] = 1;


	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == endX && y == endY) return visited[endX][endY] - 1;


		for (int i = 0; i < 8; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < l && ny < l && !visited[nx][ny]) {
				visited[nx][ny] = visited[x][y] + 1;
				q.push({ nx, ny });
			}
		}
	}

	return 0;
}


int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int l;
		cin >> l;
		int startX, startY, endX, endY;
		cin >> startX >> startY >> endX >> endY;

		cout << bfs(l, startX, startY, endX, endY) << "\n";
	}
}
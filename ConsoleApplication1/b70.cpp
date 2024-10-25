#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
bool BFS(int x, int y);
vector<vector<int>> graph;
vector < vector<bool> >visited;
int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		m = 0, n = 0;
		int k;

		cin >> m >> n >> k;

		graph.assign(m, vector<int>(n, 0));
		visited.assign(m, vector<bool>(n, false));

		//배추 입력
		for (int i = 0; i < k; i++)
		{
			int X, Y;
			cin >> X >> Y;

			graph[X][Y] = 1;
		}

		int result = 0;

		//그래프 순회
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (graph[i][j] == 1 && !visited[i][j])
				{
					if (BFS(i, j)) result++;
				}
			}
		}

		cout << result << "\n";
	}
}

bool BFS(int x, int y)
{
	//상하좌우
	int nx[4] = { -1,1,0,0 };
	int ny[4] = { 0,0,-1,1 };

	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;

	while (!q.empty())
	{
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int next_x = cur_x + nx[i];
			int next_y = cur_y + ny[i];

			if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n)
			{
				if (graph[next_x][next_y] == 1 && !visited[next_x][next_y])
				{
					visited[next_x][next_y] = true;
					q.push({ next_x,next_y });
				}
			}
		}
	}

	return true;
}
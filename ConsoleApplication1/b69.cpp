#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int BFS(int x,int y);
vector<vector<int>> house;
vector<vector<bool>> visited;
int main()
{
	cin >> n;

	house.resize(n, vector<int>(n));
	visited.resize(n, vector<bool>(n,false));

	//그래프 입력
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char c;
			cin >> c;
			//문자열-> 숫자
			house[i][j] = c - '0';
		}
	}

	vector<int> answer;

	//그래프 순회
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j] && house[i][j] == 1)
			{
				int h_cnt = BFS(i, j);
				answer.push_back(h_cnt);
			}
		}
	}
	
	//오름차순 정렬
	sort(answer.begin(), answer.end());
	cout << answer.size() << "\n";
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << "\n";
	}
}

int BFS(int x,int y)
{
	//상하좌우
	int nx[4] = { -1,1,0,0 };
	int ny[4] = { 0,0,-1,1 };

	queue<pair<int, int>> q;


	q.push({ x,y });
	visited[x][y] = true;

	int cnt = 1;

	//현재위치에서 이어져 있는 주택이 있으면 연결
	while (!q.empty())
	{
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int next_x = cur_x + nx[i];
			int next_y = cur_y + ny[i];

			if (next_x >= 0 && next_x < n && next_y>=0 && next_y < n)
			{
				if (house[next_x][next_y] == 1 && !visited[next_x][next_y])
				{
					q.push({ next_x,next_y });
					visited[next_x][next_y] = true;
					cnt++;
				}
			}
		}
	}

	return cnt;	
}

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

	//�׷��� �Է�
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char c;
			cin >> c;
			//���ڿ�-> ����
			house[i][j] = c - '0';
		}
	}

	vector<int> answer;

	//�׷��� ��ȸ
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
	
	//�������� ����
	sort(answer.begin(), answer.end());
	cout << answer.size() << "\n";
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << "\n";
	}
}

int BFS(int x,int y)
{
	//�����¿�
	int nx[4] = { -1,1,0,0 };
	int ny[4] = { 0,0,-1,1 };

	queue<pair<int, int>> q;


	q.push({ x,y });
	visited[x][y] = true;

	int cnt = 1;

	//������ġ���� �̾��� �ִ� ������ ������ ����
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

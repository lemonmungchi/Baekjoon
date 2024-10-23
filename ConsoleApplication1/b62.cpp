#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(int node);
vector<vector<int>> computers;
vector<bool> visited;
vector<int> answers;
int main()
{
	int n, m;

	cin >> n >> m;

	computers.resize(n + 1);
	answers.resize(n + 1);
	//�׷��� �Է�
	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;
		computers[s].push_back(e);
	}

	visited.resize(n + 1);

	//BFS
	for (int i = 1; i <= n; i++)
	{
		fill(visited.begin(), visited.end(), false);
		BFS(i);
	}

	//�ִ밪 ã��
	int max_val = 0;
	for (int i = 1; i <= n; i++)
	{
		max_val = max(max_val, answers[i]);
	}

	//�˻�
	for (int i = 1; i <= n; i++)
	{
		if (answers[i] == max_val)
		{
			cout << i << " ";
		}
	}
	

	return 0;
}

void BFS(int node)
{
	queue<int> q;
	q.push(node);
	visited[node] = true;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i : computers[cur])
		{
			if (visited[i] == false)
			{
				visited[i] = true;
				//��� ��ǻ�Ͷ� ����Ǿ� �ִ���
				answers[i]++;
				q.push(i);
			}
		}
	}
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void BFS(int node);

vector<vector<int>> cities;
vector<int> visitied;
vector<int> answer;
int main()
{
	int n, m, k, x;

	cin >> n >> m >> k >> x;

	cities.resize(n + 1);

	//그래프 입력받기
	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;
		cities[s].push_back(e);
	}

	visitied.resize(n + 1);

	//초기값 세팅
	for (int i = 0; i <= n; i++)
	{
		visitied[i] = -1;
	}

	BFS(x);

	for (int i = 0; i <= n; i++)
	{
		if (visitied[i] == k) answer.push_back(i);
	}

	if (answer.empty()) cout << "-1" << "\n";
	else
	{
		sort(answer.begin(), answer.end());
		for (int tmp : answer)
		{
			cout << tmp << "\n";
		}
	}
}


void BFS(int node)
{
	queue<int> q;
	q.push(node);
	visitied[node]++;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i : cities[cur])
		{
			if (visitied[i] == -1)
			{
				visitied[i] = visitied[cur] + 1;
				q.push(i);
			}
		}
	}
}
#include <iostream>
#include <vector>
using namespace std;


void DFS(int node);
vector<vector<int>> computers;
vector<bool> visited;
int cnt = 0;
int main()
{
	int n, m;
	cin >> n >> m;

	computers.resize(n + 1);
	visited.resize(n + 1);

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		computers[u].push_back(v);
		computers[v].push_back(u);
	}

	DFS(1);

	cout << cnt << "\n";
}

void DFS(int node)
{
	visited[node] = true;
	
	for (int i : computers[node])
	{
		if (!visited[i])
		{
			cnt++;
			DFS(i);
		}
	}
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(int node);
vector<vector<int>> graph;
vector<int> visited;
int order = 1;
int main()
{
	int n, m, r;
	cin >> n >> m >> r;

	graph.resize(n + 1);
	visited.resize(n + 1);
	fill(visited.begin(), visited.end(), 0);

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	// 인접 정점 내림차순으로 정렬
	for (int i = 1; i <= n; i++) {
		sort(graph[i].rbegin(), graph[i].rend());
	}

	DFS(r);

	for (int i = 1; i <= n; i++)
	{
		cout << visited[i] << "\n";
	}
}

void DFS(int node)
{
	visited[node] = order++;
	for (int next : graph[node]) {
		if (!visited[next]) {
			DFS(next);
		}
	}
}

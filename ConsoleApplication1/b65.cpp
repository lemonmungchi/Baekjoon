#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

typedef pair<int, int> edge;
//인접그래프
vector<vector<edge>> graph;
//거리
vector<int> mdistance;
//방문여부
vector<bool> visited;
//방문할 노드(거리, 노드)
priority_queue < edge, vector<edge>, greater<edge>> pq;
int  main()
{
	int v, e, s;

	cin >> v >> e >> s;

	graph.resize(v + 1);
	mdistance.resize(v + 1);
	fill(mdistance.begin(), mdistance.end(), INT_MAX);
	visited.resize(v + 1);
	fill(visited.begin(), visited.end(), false);

	//그래프 입력받기
	for (int i = 0; i < e; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;

		graph[u].push_back(make_pair(v, w));
	}

	//처음 시작점 넣기
	pq.push(make_pair(0, s));
	mdistance[s] = 0;
	//다익스트라 계산
	while (!pq.empty())
	{
		int cur_v = pq.top().second;
		pq.pop();
		if (visited[cur_v]) continue;

		visited[cur_v] = true;

		for (edge i : graph[cur_v])
		{
			int next_v = i.first;
			int next_e = i.second;

			//현재 거리보다 짧은 거리가 나오면 바꾸기
			if (mdistance[next_v] > mdistance[cur_v] + next_e)
			{
				mdistance[next_v] = mdistance[cur_v] + next_e;
				pq.push(make_pair(mdistance[next_v], next_v));
			}
		}
	}

	for (int i = 1; i <= v; i++)
	{
		if(visited[i])
		{
			cout << mdistance[i] << "\n";
		}
		else
		{
			cout << "INF" << "\n";
		}
		
	}

}
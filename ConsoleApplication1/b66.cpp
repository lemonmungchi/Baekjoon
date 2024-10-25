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

int dijkstra(int start, int end);

int  main()
{
	int v, e;

	cin >> v >> e;

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

	int start, end;
	cin >> start >> end;

	cout << dijkstra(start, end) << endl;

	return 0;
}

int dijkstra(int start, int end)
{
	//방문할 노드(거리, 노드)
	priority_queue < edge, vector<edge>, greater<edge>> pq;

	//처음 시작점과 거리값 넣기
	pq.push(make_pair(0, start));
	mdistance[start] = 0;
	//다익스트라 계산
	while (!pq.empty())
	{
		//현재 위치노드 가져오기
		int cur_v = pq.top().second;
		pq.pop();
		//방문했다면 넘어가기
		if (visited[cur_v]) continue;

		visited[cur_v] = true;

		//현재 위치에서 연결된 노드 순회
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

	return mdistance[end];
}

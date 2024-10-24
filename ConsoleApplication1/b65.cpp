#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

typedef pair<int, int> edge;
//�����׷���
vector<vector<edge>> graph;
//�Ÿ�
vector<int> mdistance;
//�湮����
vector<bool> visited;
//�湮�� ���(�Ÿ�, ���)
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

	//�׷��� �Է¹ޱ�
	for (int i = 0; i < e; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;

		graph[u].push_back(make_pair(v, w));
	}

	//ó�� ������ �ֱ�
	pq.push(make_pair(0, s));
	mdistance[s] = 0;
	//���ͽ�Ʈ�� ���
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

			//���� �Ÿ����� ª�� �Ÿ��� ������ �ٲٱ�
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
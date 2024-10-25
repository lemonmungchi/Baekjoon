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

	//�׷��� �Է¹ޱ�
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
	//�湮�� ���(�Ÿ�, ���)
	priority_queue < edge, vector<edge>, greater<edge>> pq;

	//ó�� �������� �Ÿ��� �ֱ�
	pq.push(make_pair(0, start));
	mdistance[start] = 0;
	//���ͽ�Ʈ�� ���
	while (!pq.empty())
	{
		//���� ��ġ��� ��������
		int cur_v = pq.top().second;
		pq.pop();
		//�湮�ߴٸ� �Ѿ��
		if (visited[cur_v]) continue;

		visited[cur_v] = true;

		//���� ��ġ���� ����� ��� ��ȸ
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

	return mdistance[end];
}

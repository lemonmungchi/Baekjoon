#include <iostream>
#include <vector>

using namespace std;

void DFS(int node);

vector<vector<int>> graph;
vector<int> check;
vector<bool> visited;
bool isEven;

int main()
{
	int k;
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		int v, e;
		cin >> v >> e;
		
		//�ʱ⼳��
		graph.resize(v + 1);
		check.resize(v + 1);
		visited.resize(v + 1);
		isEven = true;

		//�׷��� �Է¹ޱ�
		for (int i = 0; i < e; i++)
		{
			int start, end;
			cin >> start >> end;
			graph[start].push_back(end);
			graph[end].push_back(start);
		}

		//�׷��� ��ü ��ȸ(DFS)
		for (int i = 1; i <= v; i++)
		{
			if (isEven)
			{
				DFS(i);
			}
			else
			{
				break;
			}
		}

		if (isEven)
		{
			cout << "YES" << "\n";
		}
		else
		{
			cout << "NO" << "\n";
		}

		//�ٽ� �⺻������ �ʱ�ȭ
		for (int i = 0; i <= v; i++)
		{
			graph[i].clear();
			visited[i] = false;
			check[i] = 0;
		}
	}
}


void DFS(int node)
{
	//�湮ó��
	visited[node] = true;

	//����Ǿ��ִ� ���Ž��
	for (int i : graph[node])
	{
		//�湮���� �ʾҴٸ�
		if (!visited[i])
		{
			//�ٸ� ���տ� �߰�
			check[i] = (check[node] + 1) % 2;
			DFS(i);
		}
		//�湮�߰� ���� ���� �����̶�� ����Ŭ �߻�
		else if (check[node] == check[i]) isEven = false;
	}
}
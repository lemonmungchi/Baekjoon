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
		
		//초기설정
		graph.resize(v + 1);
		check.resize(v + 1);
		visited.resize(v + 1);
		isEven = true;

		//그래프 입력받기
		for (int i = 0; i < e; i++)
		{
			int start, end;
			cin >> start >> end;
			graph[start].push_back(end);
			graph[end].push_back(start);
		}

		//그래프 전체 순회(DFS)
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

		//다시 기본값으로 초기화
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
	//방문처리
	visited[node] = true;

	//연결되어있는 노드탐색
	for (int i : graph[node])
	{
		//방문하지 않았다면
		if (!visited[i])
		{
			//다른 집합에 추가
			check[i] = (check[node] + 1) % 2;
			DFS(i);
		}
		//방문했고 만약 같은 집합이라면 사이클 발생
		else if (check[node] == check[i]) isEven = false;
	}
}
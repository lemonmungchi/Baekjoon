#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> tree(n + 1);
	vector<int>parent(n + 1, 0);

	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}


	//BFS
	queue<int> q;
	q.push(1);
	parent[1] = -1;			//루트노드는 부모x

	while (!q.empty())
	{
		int current = q.front();
		q.pop();

		for (int next : tree[current]) {
			if (parent[next] == 0) { // 아직 방문하지 않은 노드
				parent[next] = current; // 부모 기록
				q.push(next);           // 큐에 추가
			}
		}
	}

	// 결과 출력 (2번 노드부터 N번 노드까지의 부모 출력)
	for (int i = 2; i <= n; i++) {
		cout << parent[i] << '\n';
	}

	return 0;
}
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
	parent[1] = -1;			//��Ʈ���� �θ�x

	while (!q.empty())
	{
		int current = q.front();
		q.pop();

		for (int next : tree[current]) {
			if (parent[next] == 0) { // ���� �湮���� ���� ���
				parent[next] = current; // �θ� ���
				q.push(next);           // ť�� �߰�
			}
		}
	}

	// ��� ��� (2�� ������ N�� �������� �θ� ���)
	for (int i = 2; i <= n; i++) {
		cout << parent[i] << '\n';
	}

	return 0;
}
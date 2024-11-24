#include <iostream>
#include <vector>
#include <cstring> 

using namespace std;

const int MAX = 100001; // �ִ� ��� ��
vector<pair<int, int>> tree[MAX]; // Ʈ���� ������ ���� ����Ʈ (��� ��ȣ, �Ÿ�)
bool visited[MAX]; // �湮 ���θ� ����
int maxDistance; // Ʈ���� ����
int farthestNode; // ���� �� ���


void dfs(int node, int distance) {
	visited[node] = true;

	// �ִ� �Ÿ� ����
	if (distance > maxDistance) {
		maxDistance = distance;
		farthestNode = node;
	}

	// ����� ��� �湮
	for (auto next : tree[node]) {
		int nextNode = next.first;
		int nextDistance = next.second;

		if (!visited[nextNode]) {
			dfs(nextNode, distance + nextDistance);
		}
	}
}
int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int node;
		cin >> node;
		while (true)
		{
			int Node, distance;
			cin >> Node;
			if (Node == -1) break;

			cin >> distance;
			tree[node].push_back({ Node,distance });
		}
	}

	memset(visited, false, sizeof(visited));
	maxDistance = 0;
	dfs(1, 0); // ������ ���(1��)���� ����

	// �� ��° DFS ����
	memset(visited, false, sizeof(visited));
	maxDistance = 0;
	dfs(farthestNode, 0); // ù ��° DFS���� ���� �� ��带 ���������� ����

	// Ʈ���� ���� ���
	cout << maxDistance << endl;

	return 0;
}
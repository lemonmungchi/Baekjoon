#include <iostream>
#include <vector>
#include <cstring> 

using namespace std;

const int MAX = 100001; // 최대 노드 수
vector<pair<int, int>> tree[MAX]; // 트리를 저장할 인접 리스트 (노드 번호, 거리)
bool visited[MAX]; // 방문 여부를 저장
int maxDistance; // 트리의 지름
int farthestNode; // 가장 먼 노드


void dfs(int node, int distance) {
	visited[node] = true;

	// 최대 거리 갱신
	if (distance > maxDistance) {
		maxDistance = distance;
		farthestNode = node;
	}

	// 연결된 노드 방문
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
	dfs(1, 0); // 임의의 노드(1번)에서 시작

	// 두 번째 DFS 실행
	memset(visited, false, sizeof(visited));
	maxDistance = 0;
	dfs(farthestNode, 0); // 첫 번째 DFS에서 가장 먼 노드를 시작점으로 설정

	// 트리의 지름 출력
	cout << maxDistance << endl;

	return 0;
}
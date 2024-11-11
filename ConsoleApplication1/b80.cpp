#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;

bool isSameNum(int x, int y, int size) {
	int num = graph[x][y]; // 첫 번째 칸의 수
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (graph[i][j] != num) {
				return false; // 다른 수가 섞여 있으면 false 반환
			}
		}
	}
	return true; // 모두 같다면 true
}

// 분할 정복 함수
void divideAndConquer(int x, int y, int size) {
	if (isSameNum(x, y, size)) {
		cout << graph[x][y];
	}
	else {

		cout << "(";
		
		int newSize = size / 2;
		divideAndConquer(x, y, newSize); // 왼쪽 위
		divideAndConquer(x, y + newSize, newSize); // 오른쪽 위
		divideAndConquer(x + newSize, y, newSize); // 왼쪽 아래
		divideAndConquer(x + newSize, y + newSize, newSize); // 오른쪽 아래
		cout << ")";
	}
}


int main()
{
	int n;
	cin >> n;
	graph.resize(n, vector<int>(n));

	for(int i=0;i<n;i++)
	{
		for (int j = 0; j < n; j++)
		{
			char ch;
			cin >> ch;
			graph[i][j] = ch - '0';
		}
	}

	divideAndConquer(0, 0, n);

	return 0;

}
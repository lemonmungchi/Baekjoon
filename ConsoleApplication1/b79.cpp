#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
int whitecnt = 0;
int bluecnt = 0;

bool isSameColor(int x, int y, int size) {
	int color = graph[x][y]; // 첫 번째 칸의 색
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (graph[i][j] != color) {
				return false; // 다른 색이 섞여 있으면 false 반환
			}
		}
	}
	return true; // 모두 같은 색이면 true 반환
}

// 분할 정복 함수
void divideAndConquer(int x, int y, int size) {
	if (isSameColor(x, y, size)) {
		// 모두 같은 색이면 해당 색에 따라 개수 증가
		if (graph[x][y] == 0) {
			whitecnt++;
		}
		else {
			bluecnt++;
		}
	}
	else {
		// 다른 색이 섞여 있으면 4등분하여 재귀적으로 호출
		int newSize = size / 2;
		divideAndConquer(x, y, newSize); // 왼쪽 위
		divideAndConquer(x, y + newSize, newSize); // 오른쪽 위
		divideAndConquer(x + newSize, y, newSize); // 왼쪽 아래
		divideAndConquer(x + newSize, y + newSize, newSize); // 오른쪽 아래
	}
}

int main()
{
	int n;
	cin >> n;

	graph.resize(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> graph[i][j];
		}
	}

	divideAndConquer(0, 0, n);
	
	cout << whitecnt << "\n";
	cout << bluecnt << "\n";

	return 0;
}
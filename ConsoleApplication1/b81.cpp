#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
int minuscnt = 0;
int zerocnt = 0;
int onecnt = 0;

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
		if (graph[x][y] == -1) {
			minuscnt++;
		}
		else if(graph[x][y] == 0){
			zerocnt++;
		}
		else
		{
			onecnt++;
		}
	}
	else {

		int newSize = size / 3;
		divideAndConquer(x, y, newSize); // 왼쪽 위
		divideAndConquer(x, y + newSize, newSize); // 가운데 위
		divideAndConquer(x, y + 2 * newSize, newSize); //오른쪽 위

		divideAndConquer(x + newSize, y, newSize); // 왼쪽 가운데
		divideAndConquer(x + newSize, y + newSize, newSize); // 가운데 가운데
		divideAndConquer(x + newSize, y + 2 * newSize, newSize); //오른쪽 가운데

		divideAndConquer(x + 2 * newSize, y, newSize); // 왼쪽 아래
		divideAndConquer(x + 2 * newSize, y + newSize, newSize); // 가운데 아래
		divideAndConquer(x + 2 * newSize, y + 2 * newSize, newSize); //오른쪽 아래
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

	cout << minuscnt << "\n" << zerocnt << "\n" << onecnt << "\n";

	return 0;
}
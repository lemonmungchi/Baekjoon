#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
int minuscnt = 0;
int zerocnt = 0;
int onecnt = 0;

bool isSameNum(int x, int y, int size) {
	int num = graph[x][y]; // ù ��° ĭ�� ��
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (graph[i][j] != num) {
				return false; // �ٸ� ���� ���� ������ false ��ȯ
			}
		}
	}
	return true; // ��� ���ٸ� true
}

// ���� ���� �Լ�
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
		divideAndConquer(x, y, newSize); // ���� ��
		divideAndConquer(x, y + newSize, newSize); // ��� ��
		divideAndConquer(x, y + 2 * newSize, newSize); //������ ��

		divideAndConquer(x + newSize, y, newSize); // ���� ���
		divideAndConquer(x + newSize, y + newSize, newSize); // ��� ���
		divideAndConquer(x + newSize, y + 2 * newSize, newSize); //������ ���

		divideAndConquer(x + 2 * newSize, y, newSize); // ���� �Ʒ�
		divideAndConquer(x + 2 * newSize, y + newSize, newSize); // ��� �Ʒ�
		divideAndConquer(x + 2 * newSize, y + 2 * newSize, newSize); //������ �Ʒ�
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
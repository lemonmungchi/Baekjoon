#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
int whitecnt = 0;
int bluecnt = 0;

bool isSameColor(int x, int y, int size) {
	int color = graph[x][y]; // ù ��° ĭ�� ��
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (graph[i][j] != color) {
				return false; // �ٸ� ���� ���� ������ false ��ȯ
			}
		}
	}
	return true; // ��� ���� ���̸� true ��ȯ
}

// ���� ���� �Լ�
void divideAndConquer(int x, int y, int size) {
	if (isSameColor(x, y, size)) {
		// ��� ���� ���̸� �ش� ���� ���� ���� ����
		if (graph[x][y] == 0) {
			whitecnt++;
		}
		else {
			bluecnt++;
		}
	}
	else {
		// �ٸ� ���� ���� ������ 4����Ͽ� ��������� ȣ��
		int newSize = size / 2;
		divideAndConquer(x, y, newSize); // ���� ��
		divideAndConquer(x, y + newSize, newSize); // ������ ��
		divideAndConquer(x + newSize, y, newSize); // ���� �Ʒ�
		divideAndConquer(x + newSize, y + newSize, newSize); // ������ �Ʒ�
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
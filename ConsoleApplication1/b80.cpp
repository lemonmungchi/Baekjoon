#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;

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
		cout << graph[x][y];
	}
	else {

		cout << "(";
		
		int newSize = size / 2;
		divideAndConquer(x, y, newSize); // ���� ��
		divideAndConquer(x, y + newSize, newSize); // ������ ��
		divideAndConquer(x + newSize, y, newSize); // ���� �Ʒ�
		divideAndConquer(x + newSize, y + newSize, newSize); // ������ �Ʒ�
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
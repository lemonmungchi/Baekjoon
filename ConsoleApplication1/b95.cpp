#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int main()
{
	int m, n;
	cin >> m >> n;
	vector<vector<int>> tomato(n, vector<int>(m));
	queue<pair<int, int>> q;		//����� ť
	int empty_count = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1) {
				q.push({ i, j }); // ���� �丶���� ��ġ ����
			}
			else if (tomato[i][j] == -1) {
				empty_count++; // ����ִ� ĭ ���� ī��Ʈ
			}
		}
	}

	int days = -1;
	int total_cells = n * m;
	int ripe_count = q.size() + empty_count; // �ʱ� ���� �丶��� ����ִ� ĭ
	

	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int d = 0; d < 4; d++)
			{
				int nx = x + dx[d];
				int ny = y + dy[d];

				if (nx >= 0 && nx < n && ny >= 0 && ny < m && tomato[nx][ny] == 0)
				{
					tomato[nx][ny] = 1;
					q.push({ nx,ny });
					ripe_count++;
				}
			}
		}
		days++;
	}

	// ��� ĭ�� �;����� Ȯ��
	if (ripe_count == total_cells) {
		cout << days << '\n';
	}
	else {
		cout << -1 << '\n';
	} return 0;

	return 0;
}
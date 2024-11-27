#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 6���� �̵� (��, �Ʒ�, ��, ��, ��, ��)
int dx[6] = { 0, 0, 0, 0, -1, 1 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dz[6] = { -1, 1, 0, 0, 0, 0 };

int main()
{
    int m, n, h;
    cin >> m >> n >> h;

    vector<vector<vector<int>>> tomato(h, vector<vector<int>>(n, vector<int>(m)));
    queue<pair<int, pair<int, int>>> q;  // ť�� (z, x, y) ��ǥ ����

    // �Է� �ޱ�
    for (int z = 0; z < h; z++) {
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                cin >> tomato[z][x][y];
                if (tomato[z][x][y] == 1) {
                    q.push({ z, {x, y} });  // ���� �丶�� ��ġ ť�� ����
                }
            }
        }
    }

    int days = -1;
    int total_cells = n * m * h;
    int ripe_count = q.size();

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int z = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();

            for (int d = 0; d < 6; d++) {
                int nz = z + dz[d];
                int nx = x + dx[d];
                int ny = y + dy[d];

                // �迭 ���� üũ �� ���� ���� �丶�� ã�Ƽ� ������
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && nz >= 0 && nz < h && tomato[nz][nx][ny] == 0) {
                    tomato[nz][nx][ny] = 1;  // ���� �丶��� ���� ����
                    q.push({ nz, {nx, ny} });  // ť�� �߰�
                    ripe_count++;  // ���� �丶�� �� ����
                }
            }
        }
        days++;  // �Ϸ簡 ������
    }

    // ��� �丶�䰡 �;����� Ȯ��
    if (ripe_count == total_cells) {
        cout << days << '\n';  // ��� �丶�䰡 �;����� �ҿ�� �ϼ� ���
    }
    else {
        cout << -1 << '\n';  // ���� ���� �丶�䰡 �������� -1 ���
    }

    return 0;
}

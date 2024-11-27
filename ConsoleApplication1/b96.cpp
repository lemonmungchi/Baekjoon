#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 6방향 이동 (위, 아래, 좌, 우, 앞, 뒤)
int dx[6] = { 0, 0, 0, 0, -1, 1 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dz[6] = { -1, 1, 0, 0, 0, 0 };

int main()
{
    int m, n, h;
    cin >> m >> n >> h;

    vector<vector<vector<int>>> tomato(h, vector<vector<int>>(n, vector<int>(m)));
    queue<pair<int, pair<int, int>>> q;  // 큐에 (z, x, y) 좌표 저장

    // 입력 받기
    for (int z = 0; z < h; z++) {
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                cin >> tomato[z][x][y];
                if (tomato[z][x][y] == 1) {
                    q.push({ z, {x, y} });  // 익은 토마토 위치 큐에 삽입
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

                // 배열 범위 체크 및 익지 않은 토마토 찾아서 익히기
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && nz >= 0 && nz < h && tomato[nz][nx][ny] == 0) {
                    tomato[nz][nx][ny] = 1;  // 익은 토마토로 상태 변경
                    q.push({ nz, {nx, ny} });  // 큐에 추가
                    ripe_count++;  // 익은 토마토 수 증가
                }
            }
        }
        days++;  // 하루가 지나면
    }

    // 모든 토마토가 익었는지 확인
    if (ripe_count == total_cells) {
        cout << days << '\n';  // 모든 토마토가 익었으면 소요된 일수 출력
    }
    else {
        cout << -1 << '\n';  // 익지 않은 토마토가 남았으면 -1 출력
    }

    return 0;
}

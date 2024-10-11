#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> sequence;
vector<bool> visited;

void backtrack(int depth) {
    // 현재 depth가 M과 같으면 수열을 완성했으므로 출력
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << sequence[i] << " ";
        }
        cout << "\n";
        return;
    }

    // 1부터 N까지의 숫자들을 순서대로 확인
    for (int i = 1; i <= N; i++) {
        // 이미 방문한 숫자는 제외
        if (!visited[i]) {
            visited[i] = true;          // i번째 숫자를 사용했다고 표시
            sequence.push_back(i);      // 현재 수열에 추가
            backtrack(depth + 1);       // 다음 숫자를 결정하기 위해 재귀 호출
            visited[i] = false;         // 백트래킹을 위해 i번째 숫자를 다시 사용 가능으로 변경
            sequence.pop_back();        // 수열에서 i를 제거하여 다른 경우의 수를 고려
        }
    }
}

int main() {
    cin >> N >> M;

    visited.resize(N + 1, false);  // 방문 여부를 기록하는 배열 초기화
    backtrack(0);                  // 깊이 0부터 시작해서 수열 생성
    return 0;
}

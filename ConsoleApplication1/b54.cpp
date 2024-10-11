#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> sequence;
vector<bool> visited;

void backtrack(int depth) {
    // ���� depth�� M�� ������ ������ �ϼ������Ƿ� ���
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << sequence[i] << " ";
        }
        cout << "\n";
        return;
    }

    // 1���� N������ ���ڵ��� ������� Ȯ��
    for (int i = 1; i <= N; i++) {
        // �̹� �湮�� ���ڴ� ����
        if (!visited[i]) {
            visited[i] = true;          // i��° ���ڸ� ����ߴٰ� ǥ��
            sequence.push_back(i);      // ���� ������ �߰�
            backtrack(depth + 1);       // ���� ���ڸ� �����ϱ� ���� ��� ȣ��
            visited[i] = false;         // ��Ʈ��ŷ�� ���� i��° ���ڸ� �ٽ� ��� �������� ����
            sequence.pop_back();        // �������� i�� �����Ͽ� �ٸ� ����� ���� ���
        }
    }
}

int main() {
    cin >> N >> M;

    visited.resize(N + 1, false);  // �湮 ���θ� ����ϴ� �迭 �ʱ�ȭ
    backtrack(0);                  // ���� 0���� �����ؼ� ���� ����
    return 0;
}

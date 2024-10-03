#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    queue<int> line;
    stack<int> side;
    int next = 1;

    // 대기열 입력받기
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        line.push(x);
    }

    // 대기열 처리
    while (!line.empty()) {
        if (line.front() == next) {
            // 대기열에서 바로 나갈 수 있을 때
            line.pop();
            next++;
        }
        else { // 대기열에서 바로 나갈 수 없을 때
            
            if (!side.empty() && side.top() == next) {
                // 스택에서 나갈 수 있는 경우
                side.pop();
                next++;
            }
            else {
                // 스택에 push
                side.push(line.front());
                line.pop();
            }
        }
    }

    // 스택에 남아있는 사람들 처리
    while (!side.empty() && side.top() == next) {
        side.pop();
        next++;
    }

    // 모두 순서대로 나갔는지 확인
    if (side.empty()) {
        cout << "Nice" << endl;
    }
    else {
        cout << "Sad" << endl;
    }

    return 0;
}

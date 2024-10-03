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

    // ��⿭ �Է¹ޱ�
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        line.push(x);
    }

    // ��⿭ ó��
    while (!line.empty()) {
        if (line.front() == next) {
            // ��⿭���� �ٷ� ���� �� ���� ��
            line.pop();
            next++;
        }
        else { // ��⿭���� �ٷ� ���� �� ���� ��
            
            if (!side.empty() && side.top() == next) {
                // ���ÿ��� ���� �� �ִ� ���
                side.pop();
                next++;
            }
            else {
                // ���ÿ� push
                side.push(line.front());
                line.pop();
            }
        }
    }

    // ���ÿ� �����ִ� ����� ó��
    while (!side.empty() && side.top() == next) {
        side.pop();
        next++;
    }

    // ��� ������� �������� Ȯ��
    if (side.empty()) {
        cout << "Nice" << endl;
    }
    else {
        cout << "Sad" << endl;
    }

    return 0;
}

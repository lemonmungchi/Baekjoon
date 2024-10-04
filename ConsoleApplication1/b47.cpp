#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);  // C++ 표준 입출력과 C 표준 입출력의 동기화를 비활성화
    cin.tie(NULL);  // cin과 cout의 묶음을 해제하여 성능 향상

    deque<int> dq;
    int n, x;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int order;
        cin >> order;

        switch (order) {
        case 1:
            cin >> x;
            dq.push_front(x);
            break;
        case 2:
            cin >> x;
            dq.push_back(x);
            break;
        case 3:
            if (!dq.empty()) {
                cout << dq.front() << '\n';  // '\n' 사용
                dq.pop_front();
            }
            else {
                cout << "-1\n";
            }
            break;
        case 4:
            if (!dq.empty()) {
                cout << dq.back() << '\n';  // '\n' 사용
                dq.pop_back();
            }
            else {
                cout << "-1\n";
            }
            break;
        case 5:
            cout << dq.size() << '\n';
            break;
        case 6:
            cout << (dq.empty() ? 1 : 0) << '\n';
            break;
        case 7:
            if (!dq.empty()) {
                cout << dq.front() << '\n';
            }
            else {
                cout << "-1\n";
            }
            break;
        case 8:
            if (!dq.empty()) {
                cout << dq.back() << '\n';
            }
            else {
                cout << "-1\n";
            }
            break;
        }
    }

    return 0;
}

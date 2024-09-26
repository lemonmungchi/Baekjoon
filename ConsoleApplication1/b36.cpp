#include "iostream"
#include "set"
#include "string"

using namespace std;

set<string> s;
int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string name, action;
        cin >> name >> action;

        if (action == "enter") {
            s.insert(name);  // 회사에 들어왔으면 set에 추가
        }
        else if (action == "leave") {
            s.erase(name);  // 나갔으면 set에서 제거
        }
    }

    // 역순으로 출력
    for (auto it = s.rbegin(); it != s.rend(); ++it) {
        cout << *it << '\n';
    }

    return 0;
}

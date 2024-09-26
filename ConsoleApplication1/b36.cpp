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
            s.insert(name);  // ȸ�翡 �������� set�� �߰�
        }
        else if (action == "leave") {
            s.erase(name);  // �������� set���� ����
        }
    }

    // �������� ���
    for (auto it = s.rbegin(); it != s.rend(); ++it) {
        cout << *it << '\n';
    }

    return 0;
}

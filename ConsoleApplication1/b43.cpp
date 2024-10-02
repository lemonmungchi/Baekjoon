#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    while (true) {
        string line;
        getline(cin, line);  // �� �� ��ü �Է�

        if (line == ".") break;  // ���� ����

        stack<char> s;
        bool isBalanced = true;  // ���� ���� üũ

        for (int i = 0; i < line.size(); i++) {
            if (line[i] == '(' || line[i] == '[') {
                s.push(line[i]);  // ���� ��ȣ�� ���ÿ� ����
            }
            else if (line[i] == ')') {
                if (!s.empty() && s.top() == '(') {
                    s.pop();  // ��ȣ�� ¦�� ������ ���ÿ��� ����
                }
                else {
                    isBalanced = false;  // ¦�� ���� ������ �ұ���
                    break;
                }
            }
            else if (line[i] == ']') {
                if (!s.empty() && s.top() == '[') {
                    s.pop();  // ���ȣ�� ¦�� ������ ���ÿ��� ����
                }
                else {
                    isBalanced = false;
                    break;
                }
            }
        }

        if (!s.empty()) isBalanced = false;  // ������ ��� ���� ������ �ұ���

        if (isBalanced) cout << "yes" << endl;
        else cout << "no" << endl;
    }

    return 0;
}

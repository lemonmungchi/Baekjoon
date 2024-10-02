#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    while (true) {
        string line;
        getline(cin, line);  // 한 줄 전체 입력

        if (line == ".") break;  // 종료 조건

        stack<char> s;
        bool isBalanced = true;  // 균형 여부 체크

        for (int i = 0; i < line.size(); i++) {
            if (line[i] == '(' || line[i] == '[') {
                s.push(line[i]);  // 여는 괄호를 스택에 넣음
            }
            else if (line[i] == ')') {
                if (!s.empty() && s.top() == '(') {
                    s.pop();  // 괄호가 짝이 맞으면 스택에서 제거
                }
                else {
                    isBalanced = false;  // 짝이 맞지 않으면 불균형
                    break;
                }
            }
            else if (line[i] == ']') {
                if (!s.empty() && s.top() == '[') {
                    s.pop();  // 대괄호가 짝이 맞으면 스택에서 제거
                }
                else {
                    isBalanced = false;
                    break;
                }
            }
        }

        if (!s.empty()) isBalanced = false;  // 스택이 비어 있지 않으면 불균형

        if (isBalanced) cout << "yes" << endl;
        else cout << "no" << endl;
    }

    return 0;
}

#include <iostream>
#include <stack>

using namespace std;

// VPS 판별 함수
bool isVPS(string ps)
{
    stack<char> s;

    for (int i = 0; i < ps.size(); i++)
    {
        if (ps[i] == '(') {
            s.push('(');   // 여는 괄호일 때 스택에 추가
        }
        else {
            // 닫는 괄호일 때
            if (s.empty()) {
                return false;  // 닫는 괄호가 나왔는데 스택이 비어 있으면 잘못된 괄호열
            }
            else {
                s.pop();  // 괄호 짝을 맞추는 경우
            }
        }
    }

    // 모든 괄호를 처리한 후 스택이 비어 있어야 올바른 VPS
    return s.empty();
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string ps;
        cin >> ps;
        if (isVPS(ps)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}

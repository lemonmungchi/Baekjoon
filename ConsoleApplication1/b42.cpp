#include <iostream>
#include <stack>

using namespace std;

// VPS �Ǻ� �Լ�
bool isVPS(string ps)
{
    stack<char> s;

    for (int i = 0; i < ps.size(); i++)
    {
        if (ps[i] == '(') {
            s.push('(');   // ���� ��ȣ�� �� ���ÿ� �߰�
        }
        else {
            // �ݴ� ��ȣ�� ��
            if (s.empty()) {
                return false;  // �ݴ� ��ȣ�� ���Դµ� ������ ��� ������ �߸��� ��ȣ��
            }
            else {
                s.pop();  // ��ȣ ¦�� ���ߴ� ���
            }
        }
    }

    // ��� ��ȣ�� ó���� �� ������ ��� �־�� �ùٸ� VPS
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

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a, b, c;

    while (true) {
        cin >> a >> b >> c;

        // ���� ����
        if (a == 0 && b == 0 && c == 0) break;

        // �� ���� �����Ͽ� ���� �� ���� �������� ������ ����
        int sides[3] = { a, b, c };
        sort(sides, sides + 3);

        // �ﰢ���� ���� �˻�: ���� �� ���� �ٸ� �� ���� �պ��� �۾ƾ� ��
        if (sides[2] >= sides[0] + sides[1]) {
            cout << "Invalid" << endl;
        }
        else if (sides[0] == sides[1] && sides[1] == sides[2]) {
            cout << "Equilateral" << endl;
        }
        else if (sides[0] == sides[1] || sides[1] == sides[2]) {
            cout << "Isosceles" << endl;
        }
        else {
            cout << "Scalene" << endl;
        }
    }

    return 0;
}

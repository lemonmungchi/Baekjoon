#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a, b, c;

    while (true) {
        cin >> a >> b >> c;

        // 종료 조건
        if (a == 0 && b == 0 && c == 0) break;

        // 세 변을 정렬하여 가장 긴 변이 마지막에 오도록 정렬
        int sides[3] = { a, b, c };
        sort(sides, sides + 3);

        // 삼각형의 조건 검사: 가장 긴 변이 다른 두 변의 합보다 작아야 함
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

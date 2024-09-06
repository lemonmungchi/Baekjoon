#include <iostream>

using namespace std;

int main() {
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    // XOR 연산을 통해 x 좌표와 y 좌표를 구한다
    int x4 = x1 ^ x2 ^ x3;
    int y4 = y1 ^ y2 ^ y3;

    cout << x4 << " " << y4 << endl;

    return 0;
}

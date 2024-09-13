#include <iostream>

using namespace std;

int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    int denominator = a * e - b * d;

    // 분모가 0이 아닌 경우에만 해가 존재함
    if (denominator != 0) {
        int x = (c * e - b * f) / denominator;
        int y = (a * f - c * d) / denominator;

        cout << x << " " << y << endl;
    }

    return 0;
}

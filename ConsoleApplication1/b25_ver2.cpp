#include <iostream>

using namespace std;

int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    int denominator = a * e - b * d;

    // �и� 0�� �ƴ� ��쿡�� �ذ� ������
    if (denominator != 0) {
        int x = (c * e - b * f) / denominator;
        int y = (a * f - c * d) / denominator;

        cout << x << " " << y << endl;
    }

    return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int x, y, w, h;

    cin >> x >> y >> w >> h;

    // ������ ��輱������ �Ÿ�
    int distance_to_left = x;         // (x, y)���� ���� ��輱 (0, y)������ �Ÿ�
    int distance_to_right = w - x;    // (x, y)���� ������ ��輱 (w, y)������ �Ÿ�
    int distance_to_bottom = y;       // (x, y)���� �Ʒ��� ��輱 (x, 0)������ �Ÿ�
    int distance_to_top = h - y;      // (x, y)���� ���� ��輱 (x, h)������ �Ÿ�

    // �ּڰ� ���ϱ�
    int min_value = min({ distance_to_left, distance_to_right, distance_to_bottom, distance_to_top });

    cout << min_value << endl;

    return 0;
}

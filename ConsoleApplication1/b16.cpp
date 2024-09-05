#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int x, y, w, h;

    cin >> x >> y >> w >> h;

    // 각각의 경계선까지의 거리
    int distance_to_left = x;         // (x, y)에서 왼쪽 경계선 (0, y)까지의 거리
    int distance_to_right = w - x;    // (x, y)에서 오른쪽 경계선 (w, y)까지의 거리
    int distance_to_bottom = y;       // (x, y)에서 아래쪽 경계선 (x, 0)까지의 거리
    int distance_to_top = h - y;      // (x, y)에서 위쪽 경계선 (x, h)까지의 거리

    // 최솟값 구하기
    int min_value = min({ distance_to_left, distance_to_right, distance_to_bottom, distance_to_top });

    cout << min_value << endl;

    return 0;
}

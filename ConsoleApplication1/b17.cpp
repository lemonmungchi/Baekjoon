#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {
    vector<pair<int, int>> vp(3); // 세 점을 받으므로 크기 3으로 설정

    for (int i = 0; i < 3; i++) {
        cin >> vp[i].first >> vp[i].second; // 세 점의 좌표 입력
    }

    int x, y;

    // X 좌표 구하기
    if (vp[0].first == vp[1].first) {
        x = vp[2].first;
    }
    else if (vp[0].first == vp[2].first) {
        x = vp[1].first;
    }
    else {
        x = vp[0].first;
    }

    // Y 좌표 구하기
    if (vp[0].second == vp[1].second) {
        y = vp[2].second;
    }
    else if (vp[0].second == vp[2].second) {
        y = vp[1].second;
    }
    else {
        y = vp[0].second;
    }

    cout << x << " " << y << endl; // 네 번째 점 출력

    return 0;
}

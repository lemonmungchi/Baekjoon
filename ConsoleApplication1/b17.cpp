#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {
    vector<pair<int, int>> vp(3); // �� ���� �����Ƿ� ũ�� 3���� ����

    for (int i = 0; i < 3; i++) {
        cin >> vp[i].first >> vp[i].second; // �� ���� ��ǥ �Է�
    }

    int x, y;

    // X ��ǥ ���ϱ�
    if (vp[0].first == vp[1].first) {
        x = vp[2].first;
    }
    else if (vp[0].first == vp[2].first) {
        x = vp[1].first;
    }
    else {
        x = vp[0].first;
    }

    // Y ��ǥ ���ϱ�
    if (vp[0].second == vp[1].second) {
        y = vp[2].second;
    }
    else if (vp[0].second == vp[2].second) {
        y = vp[1].second;
    }
    else {
        y = vp[0].second;
    }

    cout << x << " " << y << endl; // �� ��° �� ���

    return 0;
}

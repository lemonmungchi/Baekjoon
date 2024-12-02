#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, c;
    cin >> n >> c;

    vector<int> house(n);
    for (int i = 0; i < n; i++) {
        cin >> house[i];
    }

    // �� ��ǥ ����
    sort(house.begin(), house.end());

    int low = 1; // �ּ� �Ÿ�
    int high = house[n - 1] - house[0]; // �ִ� �Ÿ�
    int result = 0;

    while (low <= high) {
        int mid = (low + high) / 2; // ���� �Ÿ�
        int prev = house[0]; // ù ��° ���� �����⸦ ��ġ
        int count = 1; // ��ġ�� ������ ����

        // ������ ��ġ
        for (int i = 1; i < n; i++) {
            //����Ÿ����� �ָ������� ���� ������ ��ġ
            if (house[i] - prev >= mid) {
                count++;
                prev = house[i];
            }
        }

        // ������ ������ ������ �Ÿ� ����
        if (count >= c) {
            result = mid; // ���� �Ÿ� ����
            low = mid + 1;
        }

        // ������ ������ �����ϸ� �Ÿ� ����
        else {
            high = mid - 1;
        }
    }

    cout << result << endl;

    return 0;
}

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

    // 집 좌표 정렬
    sort(house.begin(), house.end());

    int low = 1; // 최소 거리
    int high = house[n - 1] - house[0]; // 최대 거리
    int result = 0;

    while (low <= high) {
        int mid = (low + high) / 2; // 현재 거리
        int prev = house[0]; // 첫 번째 집에 공유기를 설치
        int count = 1; // 설치된 공유기 개수

        // 공유기 설치
        for (int i = 1; i < n; i++) {
            //현재거리보다 멀리떨어진 집에 공유기 설치
            if (house[i] - prev >= mid) {
                count++;
                prev = house[i];
            }
        }

        // 공유기 개수가 많으면 거리 증가
        if (count >= c) {
            result = mid; // 현재 거리 저장
            low = mid + 1;
        }

        // 공유기 개수가 부족하면 거리 감소
        else {
            high = mid - 1;
        }
    }

    cout << result << endl;

    return 0;
}

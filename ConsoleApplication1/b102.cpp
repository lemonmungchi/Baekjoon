#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n; // 수열 크기
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end()); // 수열 정렬

    int target, cnt = 0;
    cin >> target; // 목표 합

    int p = 0, q = n - 1; // 투 포인터 초기화

    while (p < q) {
        int sum = v[p] + v[q];
        if (sum == target) { // 목표 합과 같으면
            cnt++;
            p++;    
            q--;    
        }
        else if (sum < target) {
            p++;    // 합이 작으면 작은 값을 증가
        }
        else {
            q--;    // 합이 크면 큰 값을 감소
        }
    }

    cout << cnt << endl; // 쌍의 개수 출력

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // dp[i]는 i번째 요소까지의 최대 부분합
    vector<int> dp(n);
    dp[0] = arr[0];
    int max_sum = dp[0];

    for (int i = 1; i < n; i++) {
        //부분합,현재위치의 값중에 큰거
        dp[i] = max(arr[i], dp[i - 1] + arr[i]);
        //지금까지 최대합과 비교
        max_sum = max(max_sum, dp[i]);
    }

    cout << max_sum << endl;

    return 0;
}

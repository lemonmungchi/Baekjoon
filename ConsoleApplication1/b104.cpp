#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int k;
        cin >> k;

        vector<int> files(k + 1);
        vector<vector<int>> dp(k + 1, vector<int>(k + 1, 0));
        vector<int> prefixSum(k + 1, 0);

        // 파일 크기 입력 & 누적합(prefix sum) 계산
        for (int i = 1; i <= k; i++) {
            cin >> files[i];
            prefixSum[i] = prefixSum[i - 1] + files[i]; // 누적합 저장
        }

        // DP 테이블 채우기 (구간 길이 2부터 K까지)
        for (int len = 2; len <= k; len++) { // 파일을 합치는 구간 길이
            for (int i = 1; i + len - 1 <= k; i++) { // 시작점
                int j = i + len - 1; // 끝점
                dp[i][j] = INT_MAX; // 최소값을 찾기 위해 큰 값으로 초기화

                // 최적의 분할점을 찾기
                for (int mid = i; mid < j; mid++) {
                    dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid + 1][j] + (prefixSum[j] - prefixSum[i - 1]));
                }
            }
        }

        // 정답 출력 (전체 파일을 합치는 최소 비용)
        cout << dp[1][k] << '\n';
    }

    return 0;
}

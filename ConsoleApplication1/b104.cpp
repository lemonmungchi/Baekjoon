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

        // ���� ũ�� �Է� & ������(prefix sum) ���
        for (int i = 1; i <= k; i++) {
            cin >> files[i];
            prefixSum[i] = prefixSum[i - 1] + files[i]; // ������ ����
        }

        // DP ���̺� ä��� (���� ���� 2���� K����)
        for (int len = 2; len <= k; len++) { // ������ ��ġ�� ���� ����
            for (int i = 1; i + len - 1 <= k; i++) { // ������
                int j = i + len - 1; // ����
                dp[i][j] = INT_MAX; // �ּҰ��� ã�� ���� ū ������ �ʱ�ȭ

                // ������ �������� ã��
                for (int mid = i; mid < j; mid++) {
                    dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid + 1][j] + (prefixSum[j] - prefixSum[i - 1]));
                }
            }
        }

        // ���� ��� (��ü ������ ��ġ�� �ּ� ���)
        cout << dp[1][k] << '\n';
    }

    return 0;
}

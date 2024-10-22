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

    // dp[i]�� i��° ��ұ����� �ִ� �κ���
    vector<int> dp(n);
    dp[0] = arr[0];
    int max_sum = dp[0];

    for (int i = 1; i < n; i++) {
        //�κ���,������ġ�� ���߿� ū��
        dp[i] = max(arr[i], dp[i - 1] + arr[i]);
        //���ݱ��� �ִ��հ� ��
        max_sum = max(max_sum, dp[i]);
    }

    cout << max_sum << endl;

    return 0;
}

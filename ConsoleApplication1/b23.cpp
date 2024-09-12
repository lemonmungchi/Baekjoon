#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> cards(n);
    for (int i = 0; i < n; i++) {
        cin >> cards[i];
    }

    int max_sum = 0;  // M을 넘지 않으면서 가장 가까운 합을 저장

    // 세 장의 카드를 고르는 모든 경우를 탐색
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                int sum = cards[i] + cards[j] + cards[k];

                // 합이 M을 넘지 않는지 확인하고, M과 가장 가까운 합을 저장
                if (sum <= m && sum > max_sum) {
                    max_sum = sum;
                }
            }
        }
    }

    cout << max_sum << endl;
    return 0;
}

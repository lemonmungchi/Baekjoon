#include <iostream>
#include <vector>

using namespace std;

int main() {


    string s;
    cin >> s;

    int n = s.size();

    // 알파벳 별 누적합 배열
    vector<vector<int>> sum(n + 1, vector<int>(26, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            sum[i][j] = sum[i - 1][j]; // 이전 값을 복사
        }
        sum[i][s[i - 1] - 'a']++; // 현재 문자의 개수를 증가
    }

    int q;
    cin >> q;

    for(int i=0;i<q;i++) 
    {
        char c;
        int l, r;
        cin >> ch >> l >> r;

        int cnt = sum[r + 1][c - 'a'] - sum[l][c - 'a']; // 구간 계산
        cout << cnt << "\n";
    }

    return 0;
}

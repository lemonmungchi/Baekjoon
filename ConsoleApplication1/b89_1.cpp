#include <iostream>
#include <vector>

using namespace std;

int main() {


    string s;
    cin >> s;

    int n = s.size();

    // ���ĺ� �� ������ �迭
    vector<vector<int>> sum(n + 1, vector<int>(26, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            sum[i][j] = sum[i - 1][j]; // ���� ���� ����
        }
        sum[i][s[i - 1] - 'a']++; // ���� ������ ������ ����
    }

    int q;
    cin >> q;

    for(int i=0;i<q;i++) 
    {
        char c;
        int l, r;
        cin >> ch >> l >> r;

        int cnt = sum[r + 1][c - 'a'] - sum[l][c - 'a']; // ���� ���
        cout << cnt << "\n";
    }

    return 0;
}

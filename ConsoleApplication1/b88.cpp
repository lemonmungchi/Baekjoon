#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
	string s;
	cin >> s;

	int n = s.size();
	map<char, vector<int>> sum;

	// 누적 합 배열 초기화
	for (char c = 'a'; c <= 'z'; c++) {
		sum[c].resize(n + 1, 0);
	}

	// 누적 합 계산
	for (int i = 1; i <= n; i++) {
		for (char c = 'a'; c <= 'z'; c++) {
			sum[c][i] = sum[c][i - 1]; // 이전 값 복사
		}
		sum[s[i - 1]][i]++; // 현재 문자에 대한 값 증가
	}

	int q;
	cin >> q;

	for (int i = 0; i < q; i++)
	{
		char c;
		int l, r;
		cin >> c >> l >> r;

		int cnt = sum[c][r + 1] - sum[c][l];
		cout << cnt << "\n";
	}

	return 0;

}
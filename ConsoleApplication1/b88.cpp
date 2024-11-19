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

	// ���� �� �迭 �ʱ�ȭ
	for (char c = 'a'; c <= 'z'; c++) {
		sum[c].resize(n + 1, 0);
	}

	// ���� �� ���
	for (int i = 1; i <= n; i++) {
		for (char c = 'a'; c <= 'z'; c++) {
			sum[c][i] = sum[c][i - 1]; // ���� �� ����
		}
		sum[s[i - 1]][i]++; // ���� ���ڿ� ���� �� ����
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
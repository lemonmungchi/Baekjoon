#include "iostream"
#include "unordered_map"
using namespace std;

unordered_map<int, bool> mp;

int main()
{
	int n, m;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		mp[x] = true;
	}

	cin >> m;

	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		if (mp[x]) {
			cout << 1 << " ";
		}
		else {
			cout << 0 << " ";
		}
	}

	return 0;
}
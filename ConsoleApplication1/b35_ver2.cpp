#include "iostream"
#include "unordered_map"
using namespace std;

unordered_map<string, bool> mp;
int main()
{
	int n, m, cnt = 0;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string word;
		cin >> word;
		mp[word] = true;
	}

	for (int i = 0; i < m; i++)
	{
		string word;
		cin >> word;
		if (mp[word]) cnt++;
	}

	cout << cnt << endl;

	return 0;
}
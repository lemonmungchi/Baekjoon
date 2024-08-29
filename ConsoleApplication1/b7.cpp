#include "iostream"
#include "string"
#include "map"
using namespace std;

bool isGroup(string s)
{
	map<char, int> smap;
	char prechar = s[0];
	smap[prechar]++;
	for (int i = 1; i <s.length(); i++) \
	{
		if (s[i-1] != s[i] && smap[s[i]] > 0) return false;
		else smap[s[i]]++;
	}
	return true;
}
int main()
{
	int n, cnt = 0;
	string s;
	
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (isGroup(s)) cnt++;
	}

	cout << cnt;
	return 0;
}
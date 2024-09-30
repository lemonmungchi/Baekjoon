#include "iostream"
#include "set"

using namespace std;

set<int> s1, s2, answer;
int main()
{
	int n, m;

	cin >> n >> m;

	//집합만들기
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		s1.insert(x);
	}

	for (int i = 0; i < m; i++)
	{
		int x;
		cin >> x;
		s2.insert(x);
	}

	int cnt = 0;

	for (auto it = s1.begin(); it != s1.end(); it++)
	{
		if (s2.find(*it) == s2.end()) cnt++;
	}

	for (auto it = s2.begin(); it != s2.end(); it++)
	{
		if (s1.find(*it) == s1.end()) cnt++;
	}

	cout << cnt << endl;
}
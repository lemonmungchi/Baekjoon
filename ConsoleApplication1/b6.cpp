#include "iostream"
#include "string"
#include "map"

using namespace std;

int main()
{
	string s;
	map<char, int> sm;
	cin >> s;

	for (int i = 0; i < s.length(); i++)
	{
		if (islower(s[i])) sm[toupper(s[i])]++;
		else sm[s[i]]++;
	}

	int maxcnt = 0;
	char mosts = '?';

	for (auto& pair : sm)
	{
		if (pair.second > maxcnt) 
		{
			maxcnt = pair.second;
			mosts = pair.first;
		}
		else if (pair.second == maxcnt) {
			mosts = '?';
		}
	}

	cout << mosts << endl;
}
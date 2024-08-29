#include "iostream"
#include "string"
#include "vector"

using namespace std;

int countCro(string s)
{
	// ũ�ξ�Ƽ�� ���ĺ� ��� ����
	vector<string> croatianAlphabets = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

	int cnt = 0;

	for (int i = 0; i < s.length();)
	{
		bool matched = false;

		for (string alpha : croatianAlphabets)
		{
			if (s.substr(i, alpha.length()) == alpha)
			{
				cnt++;
				i+=alpha.length();
				matched=true;
				break;
			}
		}

		if (!matched)
		{
			i++;
			cnt++;
		}
	}

	return cnt;
}

int main()
{
	string s;

	cin >> s;

	int result = countCro(s);
	cout << result << endl;
}
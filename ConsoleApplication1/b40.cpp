#include <iostream>
#include <set>

using namespace std;

set<string> s;
int main()
{
	string word;

	cin >> word;

	//부분 문자열 시작위치
	for (int i = 0; i < word.size(); i++)
	{
		string w = "";
		for (int j = i; j < word.size(); j++)		//부분 문자열 길이
		{
			w += word[j];
			s.insert(w);
		}
	}

	cout << s.size() << endl;
}
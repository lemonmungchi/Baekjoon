#include <iostream>
#include <set>

using namespace std;

set<string> s;
int main()
{
	string word;

	cin >> word;

	//�κ� ���ڿ� ������ġ
	for (int i = 0; i < word.size(); i++)
	{
		string w = "";
		for (int j = i; j < word.size(); j++)		//�κ� ���ڿ� ����
		{
			w += word[j];
			s.insert(w);
		}
	}

	cout << s.size() << endl;
}
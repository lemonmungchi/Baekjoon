#include "iostream"
#include "vector"
#include "set"
#include "algorithm"

using namespace std;

// ���� ���� �Լ�
bool cmp(const string& a, const string& b) {
	if (a.length() == b.length()) {
		return a < b;  // ���̰� ������ ������ ����
	}
	return a.length() < b.length();  // ���̰� �ٸ��� ª�� ������ ����
}

int main()
{
	int n;

	cin >> n;
	set<string> s;

	for (int i = 0; i < n; i++)
	{
		string word;
		cin >> word;
		s.insert(word);
	}

	//set -> vector
	vector<string> v(s.begin(), s.end());

	sort(v.begin(), v.end(),cmp);

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	return 0;
}
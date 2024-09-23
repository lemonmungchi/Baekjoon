#include "iostream"
#include "vector"
#include "set"
#include "algorithm"

using namespace std;

// 정렬 기준 함수
bool cmp(const string& a, const string& b) {
	if (a.length() == b.length()) {
		return a < b;  // 길이가 같으면 사전순 정렬
	}
	return a.length() < b.length();  // 길이가 다르면 짧은 순으로 정렬
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
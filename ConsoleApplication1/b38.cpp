#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

unordered_map<string, bool>hear;
vector<string> both;
int main()
{
	int n, m, cnt = 0;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string person;
		cin >> person;
		hear[person] = true;
	}

	for (int i = 0; i < m; i++)
	{
		string person;
		cin >> person;
		//중복되는 단어라면
		if (hear[person])
		{
			both.push_back(person);
		}
	}

	// 사전 순으로 정렬
	sort(both.begin(), both.end());

	cout << both.size() << '\n';  
	for (const auto& name : both) {
		cout << name << '\n'; 
	}

	return 0;
}
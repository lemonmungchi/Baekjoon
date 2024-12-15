#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	vector<int> answer;

	for (int i = 1; i < n; i++)
	{
		if (v[i - 1] != v[i]) answer.push_back(v[i]);
	}

	cout << answer.size() << "\n";


}
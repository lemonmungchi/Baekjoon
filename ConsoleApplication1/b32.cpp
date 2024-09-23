#include "iostream"
#include "vector"
#include "utility"
#include "algorithm"

using namespace std;

bool cmp(pair<pair<string, int>, int>vp1, pair<pair<string, int>, int>vp2)
{
	if (vp1.first.second == vp2.first.second)
		return vp1.second < vp2.second;
	else
		return vp1.first.second < vp2.first.second;
}

vector<pair<pair<string, int>, int>> vpp;
int main()
{
	int n, cnt = 1;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string name;
		int age;
		cin >> age >> name;
		vpp.push_back({ { name,age }, cnt });
		cnt++;
	}

	sort(vpp.begin(), vpp.end(), cmp);

	for (int i = 0; i < n; i++)
	{
		cout << vpp[i].first.second << " " << vpp[i].first.first << endl;
	}

	return 0;
}
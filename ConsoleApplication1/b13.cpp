#include "iostream"
#include "vector"
#include "cmath"

using namespace std;

bool isValue(int n)
{
	if (n == 1) return false;
	
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0) return false;
	}

	return true;
}

vector<int> v;
int main()
{
	int n, cnt = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int j;
		cin >> j;
		v.push_back(j);
	}

	for (int i = 0; i < v.size(); i++)
	{
		if (isValue(v[i])) cnt++;
	}

	cout << cnt << endl;
	return 0;
}
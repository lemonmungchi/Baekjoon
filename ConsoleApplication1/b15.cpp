#include "iostream"
#include "vector"
#include "cma"

using namespace std;

int main()
{
	int n;
	vector<int> v;
	cin >> n;

	if (n == 1) cout << "" << endl;

	for (int i = 2; i <= n;)
	{
		if (n % i == 0)
		{
			n /= i;
			v.push_back(i);
		}
		else
		{
			i++;
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}


	return 0;
}
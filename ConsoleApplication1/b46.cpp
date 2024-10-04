#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> v;
queue<int> q;
int main()
{
	int n, k, cnt = 1;

	cin >> n >> k;

	for (int i = 1; i <= n; i++)		//큐 초기화
	{
		q.push(i);
	}


	while (v.size() != n)
	{
		if (cnt < k)
		{
			cnt++;
			q.push(q.front());
			q.pop();
		}
		else
		{
			v.push_back(q.front());
			q.pop();
			cnt = 1;
		}
	}

	cout << "<";
	for (int i = 0; i < n; i++)
	{
		if (i < n - 1)
		{
			cout << v[i] << ", ";
		}
		else
		{
			cout << v[i] << ">" << endl;
		}
	}


	return 0;
}
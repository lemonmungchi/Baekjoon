#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int t;
	cin >> t;

	int n, m;
	cin >> n >> m;

	vector<vector<int>> graph(n+1);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}


}
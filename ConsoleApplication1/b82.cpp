#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> a;
vector<vector<int>> b;
vector < vector<int>> result;

int main()
{
	int n, m, k;
	cin >> n >> m;
	a.resize(n, vector<int>(m));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}

	cin >> m >> k;
	b.resize(m, vector<int>(k));

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cin >> b[i][j];
		}
	}


	//Çà·Ä°ö¼À
	result.resize(n, vector<int>(k, 0));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			for (int p = 0; p < m; p++) {
				result[i][j] += a[i][p] * b[p][j];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;

}
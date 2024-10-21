#include <iostream>

using namespace std;

//dp활용 : 점화식을 구해야한다.
int main()
{
	int n;

	cin >> n;

	if (n == 1)
	{
		cout << 1 << endl;
		return 0;
	}

	int p1 = 1;			//p[n-2]
	int p2 = 2;			//p[n-1]
	int p_n = 0;

	//dp계산
	for (int i = 3; i <= n; i++)
	{
		p_n = (p1 + p2) % 15746;
		p1 = p2;
		p2 = p_n;
	}

	cout << p2 << endl;

	return 0;
}
#include <iostream>
#include <queue>
using namespace std;

int main()
{

	ios::sync_with_stdio(false);  // C와 C++의 I/O 동기화 비활성화
	cin.tie(NULL);  // 입출력 독립 처리

	int n;
	cin >> n;
	priority_queue<int> pq;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if (x > 0)
		{
			pq.push(x);
		}
		else
		{
			if (!pq.empty())
			{
				cout << pq.top() << "\n";
				pq.pop();
			}
			else
			{
				cout << 0 << "\n";
			}
		}
	}

	return 0;
}
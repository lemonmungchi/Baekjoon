#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> apartments;
vector<int> apart_time;
vector<int> indegree;		//진입 차수배열
int main()
{
	int n;
	cin >> n;

	apartments.resize(n + 1);
	apart_time.resize(n + 1);
	indegree.resize(n + 1);

	//각 건물정보 입력
	for (int i = 1; i <= n; i++)
	{
		//각 시간 입력
		cin >> apart_time[i];

		//먼저 지어야하는 건물 입력
		while (true)
		{
			int apt;
			cin >> apt;

			if (apt == -1) break;
			
			apartments[apt].push_back(i);
			indegree[i]++;
		}
	}

	queue<int> q;

	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0)
			q.push(i);
	}

	vector<int> answer;
	answer.resize(n + 1);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i : apartments[cur])
		{
			indegree[i]--;
			//기존 값 vs 선행 건물시간추가 
			answer[i] = max(answer[i], answer[cur] + apart_time[cur]);
			if (indegree[i] == 0)
			{
				q.push(i);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << answer[i] + apart_time[i] << "\n";
	}
}
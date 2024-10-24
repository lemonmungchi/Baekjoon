#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> apartments;
vector<int> apart_time;
vector<int> indegree;		//���� �����迭
int main()
{
	int n;
	cin >> n;

	apartments.resize(n + 1);
	apart_time.resize(n + 1);
	indegree.resize(n + 1);

	//�� �ǹ����� �Է�
	for (int i = 1; i <= n; i++)
	{
		//�� �ð� �Է�
		cin >> apart_time[i];

		//���� ������ϴ� �ǹ� �Է�
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
			//���� �� vs ���� �ǹ��ð��߰� 
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
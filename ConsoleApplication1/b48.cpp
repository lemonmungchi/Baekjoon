#include <iostream>
#include <deque>
#include <vector>

using namespace std;

vector<int> answer;
int main()
{
	int n, tmp = 0;

	cin >> n;

	deque<pair<int, int>> balloons; 

	for (int i = 0; i < n; i++) 
	{
		int value;
		cin >> value;
		balloons.push_back({ i + 1, value }); // 풍선 번호 / 종이에 적힌 값
	}


	while (!balloons.empty())
	{
		auto current = balloons.front();
		balloons.pop_front();
		answer.push_back(current.first);

		if (balloons.empty()) break;

		int steps = current.second;

		if (steps > 0)
		{
			for (int i = 0; i < steps - 1; i++) { // 오른쪽으로 이동
				balloons.push_back(balloons.front());
				balloons.pop_front();
			}
		}
		else
		{
			for (int i = 0; i < -steps; i++) { // 왼쪽으로 이동
				balloons.push_front(balloons.back());
				balloons.pop_back();
			}
		}
	}

	for (int i = 0; i < answer.size(); i++) {
		if (i != 0) cout << " ";
		cout << answer[i];
	}

	return 0;

}
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;
vector<int> numbers;
int maxResult = INT_MIN, minResult = INT_MAX;
int operators[4]; // +, -, *, /

//몇번째 숫자, 지금까지의 결과
void backtrack(int index, int currentResult)
{
	//완료조건
	if (index == n) {
		maxResult = max(maxResult, currentResult);
		minResult = min(minResult, currentResult);
	}

	//진행조건

	for (int i = 0; i < 4; i++)
	{
		if (operators[i] > 0)
		{
			operators[i]--;
			int nextResult = currentResult;

			if (i == 0) nextResult += numbers[index];      // 덧셈
			else if (i == 1) nextResult -= numbers[index]; // 뺄셈
			else if (i == 2) nextResult *= numbers[index]; // 곱셈
			else if (i == 3) {                             // 나눗셈
				if (nextResult < 0) // 음수 나눗셈 처리
					nextResult = -(-nextResult / numbers[index]);
				else
					nextResult /= numbers[index];
			}

			//연산마다 재귀
			backtrack(index + 1, nextResult); // 다음 단계로 진행
			operators[i]++; // 연산자 복원
		}	
	}
}


int main()
{
	cin >> n;

	numbers.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> numbers[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> operators[i]; // +, -, *, /
	}

	backtrack(1, numbers[0]);

	cout << maxResult << '\n' << minResult << '\n';

	return 0;

}
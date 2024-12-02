#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;
vector<int> numbers;
int maxResult = INT_MIN, minResult = INT_MAX;
int operators[4]; // +, -, *, /

//���° ����, ���ݱ����� ���
void backtrack(int index, int currentResult)
{
	//�Ϸ�����
	if (index == n) {
		maxResult = max(maxResult, currentResult);
		minResult = min(minResult, currentResult);
	}

	//��������

	for (int i = 0; i < 4; i++)
	{
		if (operators[i] > 0)
		{
			operators[i]--;
			int nextResult = currentResult;

			if (i == 0) nextResult += numbers[index];      // ����
			else if (i == 1) nextResult -= numbers[index]; // ����
			else if (i == 2) nextResult *= numbers[index]; // ����
			else if (i == 3) {                             // ������
				if (nextResult < 0) // ���� ������ ó��
					nextResult = -(-nextResult / numbers[index]);
				else
					nextResult /= numbers[index];
			}

			//���긶�� ���
			backtrack(index + 1, nextResult); // ���� �ܰ�� ����
			operators[i]++; // ������ ����
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
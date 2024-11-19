#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k; 

	vector<int> v(n, 0);

	// �迭 �Է� �� ���� �� ���
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int sum = 0;
	for (int i = 0; i < k; i++)
	{
		sum += v[i];
	}

	int max_sum = sum;

	//�����̵� ������
	for (int i = k; i < n; i++)
	{
		sum += v[i] - v[i - k];
		max_sum = max(max_sum, sum);
	}

	cout << max_sum << "\n";

	return 0;
}
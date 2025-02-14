#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp_lis(vector<int>& v)
{
	int size = v.size();
	vector<int> dp1(size, 1), dp2(size, 1);

	//����->������
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (v[j] < v[i])
			{
				dp1[i] = max(dp1[i], dp1[j] + 1);
			}
		}
	}

	//������->����
	for (int i = size - 1; i >= 0; i--)
	{
		for (int j = size - 1; j > i; j--)
		{
			if (v[j] < v[i])
			{
				dp2[i] = max(dp2[i], dp2[j] + 1);
			}
		}
	}

	// �� `i`���� `dp1[i] + dp2[i] - 1`�� �ִ� ã��
	int maxLength = 0;
	for (int i = 0; i < size; i++) {
		maxLength = max(maxLength, dp1[i] + dp2[i] - 1);
	}

	return maxLength;
}


int main()
{
	int n;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	cout << dp_lis(v) << "\n";
}
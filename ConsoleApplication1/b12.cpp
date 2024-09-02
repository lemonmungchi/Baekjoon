#include "iostream"
#include "vector"
#include "cmath"
#include "algorithm"

using namespace std;

int main()
{
	int n;
	while (true)
	{
		cin >> n;
		if (n == -1) return 0;

		vector<int> v;
		int sum = 0;
		for (int i = 1; i <= sqrt(n); i++)
		{
			if (n % i == 0)
			{
				v.push_back(i);
				if (i != 1 && i != n / i)  //n / i�� �ٸ� ���
				{
					v.push_back(n / i); // ��� n/i �߰�
				}
				sum += i;  // ����� �տ� �߰�
				if (i != 1 && i != n / i)
				{
					sum += n / i; // n / i�� ����� ��� �տ� �߰�
				}
			}
		}
		sort(v.begin(), v.end());
		// ������ �Ǻ�
		if (sum == n)
		{
			cout << n << " = ";
			for (int i = 0; i < v.size(); i++)
			{
				cout << v[i];
				if (i != v.size() - 1)
				{
					cout << " + ";
				}
			}
			cout << endl;
		}
		else
		{
			cout << n << " is NOT perfect." << endl;
		}
	}
}
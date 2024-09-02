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
				if (i != 1 && i != n / i)  //n / i과 다를 경우
				{
					v.push_back(n / i); // 약수 n/i 추가
				}
				sum += i;  // 약수의 합에 추가
				if (i != 1 && i != n / i)
				{
					sum += n / i; // n / i가 약수일 경우 합에 추가
				}
			}
		}
		sort(v.begin(), v.end());
		// 완전수 판별
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
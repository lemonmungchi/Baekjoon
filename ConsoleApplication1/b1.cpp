#include <iostream>
using namespace std;

long long fac(int n)
{
	if (n <= 1)
		return 1;
	else
		return n * fac(n - 1);
}

int main() 
{
	int n;
	long long sum;
	cin >> n;

	sum =fac(n);

	cout << sum;

	return 0;
}
#include <iostream>

using namespace std;

long fac(int n)
{
	if (n <= 1)return 1;
	else return n * fac(n-1);
}

int main()
{
	int n;
	cin >> n;


	cout << fac(n) << endl;
}
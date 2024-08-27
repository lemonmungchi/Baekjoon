#include "iostream"

using namespace std;

long long fi(int n)
{
	if (n <= 1) return n;
	else return fi(n - 1) + fi(n - 2);
}

int main() 
{
	int n;
	long long fibo;
	cin >> n;

	fibo = fi(n);
	cout << fibo;

	return 0;
}
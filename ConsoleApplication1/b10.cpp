#include "iostream"
#include "cmath"

using namespace std;

int main()
{
	int a, b, v;

	cin >> a >> b >> v;
	
	int days = ceil((double)(v - a) / (a - b)) + 1;

	cout << days;
	return 0;
}
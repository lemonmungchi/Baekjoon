#include "iostream"
#include "vector"
#include "cmath"

using namespace std;

int main()
{
	int n;
	vector<int> v;
	cin >> n;

	if (n == 1) cout << "" << endl;

	for (int i = 2; i <= sqrt(n); i++) {
		while (n % i == 0) {
			n /= i;
			v.push_back(i);
		}
	}

	// 남아있는 소수 `n`이 있다면 그것도 출력
	if (n > 1) {
		v.push_back(n);
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}


	return 0;
}
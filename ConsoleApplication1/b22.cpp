#include "iostream"
#include "algorithm"

using namespace std;

int main()
{
	int a, b, c;

	cin >> a >> b >> c;

	// 세 변을 정렬하여 가장 긴 변이 마지막에 오도록 정렬
	int sides[3] = { a, b, c };
	sort(sides, sides + 3);

	for (int i = sides[2]; i >= sides[0]; i--)
	{
		if (i < sides[0] + sides[1])
		{
			sides[2] = i;
			break;
		}
	}

	int sum = sides[0] + sides[1] + sides[2];

	cout << sum << endl;
}
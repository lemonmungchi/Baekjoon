#include "iostream"
#include "algorithm"

using namespace std;

int main()
{
	int a, b, c;

	cin >> a >> b >> c;

	// �� ���� �����Ͽ� ���� �� ���� �������� ������ ����
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
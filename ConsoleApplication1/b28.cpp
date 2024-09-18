#include "iostream"

using namespace std;

int main()
{
	// d: 현재 대각선 번호 , cnt : 분수의 총 개수
	int x, d = 1, cnt = 0;

	cin >> x;

	//대각선에 속하는 개수까지 증가시켜줌
	while (cnt+d < x)
	{
		cnt += d;
		d++;
	}

	//순서-지금까지의 분수 개수 = 위치
	int idx = x - cnt;
	int answer_x, answer_y;				//분자, 분모

	//짝수이면 아래 홀수이면 위로 감
	if (d % 2 == 0)
	{
		answer_x = idx;
		answer_y = d - idx + 1;

	}
	else
	{
		answer_x = d - idx + 1;
		answer_y = idx;
	}

	cout << answer_x << "/" << answer_y << endl;

	return 0;
}
#include "iostream"

using namespace std;

int main()
{
	// d: ���� �밢�� ��ȣ , cnt : �м��� �� ����
	int x, d = 1, cnt = 0;

	cin >> x;

	//�밢���� ���ϴ� �������� ����������
	while (cnt+d < x)
	{
		cnt += d;
		d++;
	}

	//����-���ݱ����� �м� ���� = ��ġ
	int idx = x - cnt;
	int answer_x, answer_y;				//����, �и�

	//¦���̸� �Ʒ� Ȧ���̸� ���� ��
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
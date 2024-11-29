#include <iostream>
#include <vector>

using namespace std;

int n;
int result = 0;
vector<int> board;

bool isSafe(int row, int col)
{
	//���྿ Ž��
	for (int i = 0; i < row; i++)
	{
		//������ | �밢��
		if (board[i] == col || abs(board[i] - col) == row - i)
			return false;
	}

	return true;
}

void solve(int row) {
    if (row == n) {     //���� ���� �����ߴٸ�
        result++;       //����� �� �߰�
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) { // ���� ��ġ�� ���� ���� �� �ִٸ�
            board[row] = col;  // ���� ����
			solve(row + 1); // ���� ������ ����
        }
    }
}

int main()
{
	cin >> n;
	board.resize(n);
	solve(0);

	cout << result << "\n";

	return 0;
}
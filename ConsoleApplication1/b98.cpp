#include <iostream>
#include <vector>

using namespace std;

int n;
int result = 0;
vector<int> board;

bool isSafe(int row, int col)
{
	//한행씩 탐색
	for (int i = 0; i < row; i++)
	{
		//같은열 | 대각선
		if (board[i] == col || abs(board[i] - col) == row - i)
			return false;
	}

	return true;
}

void solve(int row) {
    if (row == n) {     //만약 끝에 도달했다면
        result++;       //경우의 수 추가
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) { // 현재 위치에 퀸을 놓을 수 있다면
            board[row] = col;  // 퀸을 놓음
			solve(row + 1); // 다음 행으로 진행
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
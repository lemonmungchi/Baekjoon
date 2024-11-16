#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000;

// 두 행렬을 곱하는 함수
vector<vector<int>> multiply(const vector<vector<int>>& A, const vector<vector<int>>& B, int N) {
    vector<vector<int>> result(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return result;
}

// 행렬을 거듭제곱하는 함수 (분할 정복)
vector<vector<int>> matrixPower(const vector<vector<int>>& A, long long B, int N) {
    if (B == 1) {
        return A; // A^1 = A
    }

    vector<vector<int>> halfPower = matrixPower(A, B / 2, N);
    vector<vector<int>> halfResult = multiply(halfPower, halfPower, N);

    if (B % 2 == 0) {
        return halfResult;
    }
    else {
        return multiply(halfResult, A, N);
    }
}

int main() {
    int N;
    long long B;
    cin >> N >> B;

    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
            A[i][j] %= MOD; // 입력 시 1000으로 나눈 나머지로 저장
        }
    }

    vector<vector<int>> result = matrixPower(A, B, N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

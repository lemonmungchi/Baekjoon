#include <iostream>
#include <vector>

using namespace std;

int cnt1 = 0; // 재귀 호출 횟수 카운트

// 재귀 방식 피보나치 함수
long fib(int n) {
    if (n == 1 || n == 2) {
        cnt1++;
        return 1;
    }
    else {
        return (fib(n - 1) + fib(n - 2));
    }
}

// 동적 프로그래밍 방식 피보나치 함수
int fib2(int n) {
    vector<int> f(n + 1); // 배열 크기를 n + 1로 선언
    f[1] = f[2] = 1;
    int cnt2 = 0;

    // 피보나치 수열 계산 및 코드2 실행 횟수 카운트
    for (int i = 3; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
        cnt2++;
    }

    return cnt2; // 코드2 실행 횟수 반환
}

int main() {
    int n;
    cin >> n;

    fib(n); // 재귀 피보나치 계산
    int cnt2 = fib2(n); // 동적 프로그래밍 피보나치 계산

    cout << cnt1 << " " << cnt2 << endl;

    return 0;
}

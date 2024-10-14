#include <iostream>
#include <vector>

using namespace std;

int cnt1 = 0; // ��� ȣ�� Ƚ�� ī��Ʈ

// ��� ��� �Ǻ���ġ �Լ�
long fib(int n) {
    if (n == 1 || n == 2) {
        cnt1++;
        return 1;
    }
    else {
        return (fib(n - 1) + fib(n - 2));
    }
}

// ���� ���α׷��� ��� �Ǻ���ġ �Լ�
int fib2(int n) {
    vector<int> f(n + 1); // �迭 ũ�⸦ n + 1�� ����
    f[1] = f[2] = 1;
    int cnt2 = 0;

    // �Ǻ���ġ ���� ��� �� �ڵ�2 ���� Ƚ�� ī��Ʈ
    for (int i = 3; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
        cnt2++;
    }

    return cnt2; // �ڵ�2 ���� Ƚ�� ��ȯ
}

int main() {
    int n;
    cin >> n;

    fib(n); // ��� �Ǻ���ġ ���
    int cnt2 = fib2(n); // ���� ���α׷��� �Ǻ���ġ ���

    cout << cnt1 << " " << cnt2 << endl;

    return 0;
}

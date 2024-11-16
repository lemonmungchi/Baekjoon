#include <iostream>
using namespace std;

// ���� ������ �̿��� �ŵ����� �Լ�
long long modExp(long long a, long long b, long long c) {
    if (b == 0) return 1;           // A^0 = 1
    if (b == 1) return a % c;        // A^1 = A % C

    long long half = modExp(a, b / 2, c); // A^(B/2) ���

    if (b % 2 == 0) {
        // B�� ¦���� ���
        return (half * half) % c;
    }
    else {
        // B�� Ȧ���� ���
        return ((half * half) % c * a % c) % c;
    }
}

int main() {
    long long a, b, c;
    cin >> a >> b >> c;

    cout << modExp(a, b, c) << endl;

    return 0;
}

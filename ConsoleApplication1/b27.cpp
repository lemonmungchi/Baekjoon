#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int count = 0;

    
    while (n >= 0) {
        if (n % 5 == 0) {  // 5�� ������ ��������
            count += n / 5;  // 5kg ���� ���� ����
            cout << count << endl;
            return 0;
        }
        n -= 3;  // 5�� ������ �������� ������ 3kg ������ �ϳ� ���
        count++;  // 3kg ���� ��������Ƿ� ���� ���� �߰�
    }

    // ���� ��Ȯ�� N kg�� ���� �� ������ -1 ���
    cout << -1 << endl;
    return 0;
}

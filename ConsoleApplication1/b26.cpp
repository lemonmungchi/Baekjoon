#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    int count = 0;
    int number = 666;  // ù ��° ������ ���� 666

    // n��° ������ ���� ã�� ������ �ݺ�
    while (true) {
        // ���� ���ڿ� "666"�� ���ԵǾ� ������ ī��Ʈ ����
        if (to_string(number).find("666") != string::npos) {
            count++;
        }

        // n��° ������ ���� ã�� ��� ��� �� ����
        if (count == n) {
            cout << number << endl;
            break;
        }

        // ���� ���ڷ� �̵�
        number++;
    }

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

vector<int> players_c(3);      // �� �÷��̾��� �ֱ�
vector<int> players_damage(3); // �� �÷��̾��� ������
int boss;

int main() {
    // �� �÷��̾��� �ֱ�� ������ �Է�
    for (int i = 0; i < 3; i++) {
        cin >> players_c[i] >> players_damage[i];
    }

    // ������ ü�� �Է�
    cin >> boss;

    int time = 0;
    int total_damage = players_damage[0] + playrs_damage[1] + players_damage[2];

    // 0�ʿ� ��� ����ũ��Ʈ�� ���ÿ� ������ ���Ѵ�.
    boss -= total_damage;

    // ������ ü���� 0 �������� Ȯ��
    if (boss <= 0) {
        cout << time << endl;
        return 0;
    }

    // �� ������ ������ �ݺ��Ѵ�.
    while (boss > 0) {
        time++;
        for (int i = 0; i < 3; i++) {
            // �� �÷��̾��� �ֱ⿡ ���� ����
            if (time % players_c[i] == 0) {
                boss -= players_damage[i];
            }
        }
    }

    // ������ ü���� 0 ���ϰ� �� �ð� ���
    cout << time << endl;

    return 0;
}

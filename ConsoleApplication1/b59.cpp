#include <iostream>
#include <vector>

using namespace std;

vector<int> players_c(3);      // 각 플레이어의 주기
vector<int> players_damage(3); // 각 플레이어의 데미지
int boss;

int main() {
    // 각 플레이어의 주기와 데미지 입력
    for (int i = 0; i < 3; i++) {
        cin >> players_c[i] >> players_damage[i];
    }

    // 보스의 체력 입력
    cin >> boss;

    int time = 0;
    int total_damage = players_damage[0] + playrs_damage[1] + players_damage[2];

    // 0초에 모든 마스크로트가 동시에 공격을 가한다.
    boss -= total_damage;

    // 보스의 체력이 0 이하인지 확인
    if (boss <= 0) {
        cout << time << endl;
        return 0;
    }

    // 초 단위로 공격을 반복한다.
    while (boss > 0) {
        time++;
        for (int i = 0; i < 3; i++) {
            // 각 플레이어의 주기에 맞춰 공격
            if (time % players_c[i] == 0) {
                boss -= players_damage[i];
            }
        }
    }

    // 보스의 체력이 0 이하가 된 시간 출력
    cout << time << endl;

    return 0;
}

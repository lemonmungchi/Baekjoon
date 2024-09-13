#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    int count = 0;
    int number = 666;  // 첫 번째 종말의 수는 666

    // n번째 종말의 수를 찾을 때까지 반복
    while (true) {
        // 현재 숫자에 "666"이 포함되어 있으면 카운트 증가
        if (to_string(number).find("666") != string::npos) {
            count++;
        }

        // n번째 종말의 수를 찾은 경우 출력 후 종료
        if (count == n) {
            cout << number << endl;
            break;
        }

        // 다음 숫자로 이동
        number++;
    }

    return 0;
}

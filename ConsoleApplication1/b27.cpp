#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int count = 0;

    
    while (n >= 0) {
        if (n % 5 == 0) {  // 5로 나누어 떨어지면
            count += n / 5;  // 5kg 봉지 개수 더함
            cout << count << endl;
            return 0;
        }
        n -= 3;  // 5로 나누어 떨어지지 않으면 3kg 봉지를 하나 사용
        count++;  // 3kg 봉지 사용했으므로 봉지 개수 추가
    }

    // 만약 정확히 N kg을 만들 수 없으면 -1 출력
    cout << -1 << endl;
    return 0;
}

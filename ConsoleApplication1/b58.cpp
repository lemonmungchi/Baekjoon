#include <iostream>

using namespace std;

int main()
{
    int t;

    cin >> t;

    long p[101] = { 0 };

    p[1] = p[2] = p[3] = 1;

    // 배열 미리 계산 
    for (int i = 4; i <= 100; i++) {
        p[i] = p[i - 2] + p[i - 3];
    }

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        cout << p[n] << endl;
    }

    return 0;
}
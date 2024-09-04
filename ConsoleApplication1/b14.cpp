#include "iostream"
#include "vector"
#include "cmath"

using namespace std;

// 에라토스테네스의 체로 소수 목록을 생성
vector<bool> sieve(int max) {
    vector<bool> is_prime(max + 1, true);
    is_prime[0] = is_prime[1] = false; // 0과 1은 소수가 아님

    for (int i = 2; i * i <= max; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= max; j += i) {
                is_prime[j] = false;
            }
        }
    }

    return is_prime;
}

int main()
{
    int m, n, sum = 0;
    vector<int> sumv;
    cin >> m >> n;

    vector<bool> is_prime = sieve(n);

    for (int i = m; i <= n; i++)
    {
        if (is_prime[i])
        {
            sumv.push_back(i);
            sum += i;
        }
    }

    if (sumv.size() > 0) cout << sum << "\n" << sumv[0] << endl;
    else cout << -1 << endl;

    return 0;

}
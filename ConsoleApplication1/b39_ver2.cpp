#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    set<int> s1, s2;  // 두 집합을 저장할 set

    // 집합 A 입력
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s1.insert(x);
    }

    // 집합 B 입력
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        s2.insert(x);
    }

    vector<int> diff1, diff2;  // 차집합을 저장할 벡터

    // A - B 차집합
    set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(diff1));

    // B - A 차집합
    set_difference(s2.begin(), s2.end(), s1.begin(), s1.end(), back_inserter(diff2));

    // 대칭 차집합의 원소 개수
    cout << diff1.size() + diff2.size() << endl;

    return 0;
}

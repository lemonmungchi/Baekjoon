#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    vector<int> sorted_v;

    // 좌표 입력받기
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sorted_v.push_back(v[i]);
    }

    // 중복 제거 후 정렬
    sort(sorted_v.begin(), sorted_v.end());
    sorted_v.erase(unique(sorted_v.begin(), sorted_v.end()), sorted_v.end());

    // 좌표 압축 적용: 각 값의 압축된 인덱스를 저장
    map<int, int> compression;
    for (int i = 0; i < sorted_v.size(); i++) {
        compression[sorted_v[i]] = i;
    }

    // 원래 좌표에 대해 압축된 결과 출력
    for (int i = 0; i < n; i++) {
        cout << compression[v[i]] << " ";
    }

    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 접미사 배열 생성 함수
vector<int> build_suffix_array(const string& s) {
    int n = s.size();
    vector<pair<string, int>> suffixes;  // 접미사와 그 접미사가 시작하는 인덱스를 저장하는 벡터

    // 모든 접미사를 생성
    for (int i = 0; i < n; i++) {
        suffixes.push_back({ s.substr(i), i });
    }

    // 접미사를 사전순으로 정렬
    sort(suffixes.begin(), suffixes.end());

    // 접미사 배열에 접미사가 시작되는 인덱스만 저장
    vector<int> suffix_array(n);
    for (int i = 0; i < n; i++) {
        suffix_array[i] = suffixes[i].second;
    }

    return suffix_array;
}

int main() {
    string s;
    cin >> s;

    // 접미사 배열 생성
    vector<int> suffix_array = build_suffix_array(s);

    // 접미사 배열 출력
    for (int i : suffix_array) {
        cout << i << " ";  // 접미사의 시작 인덱스를 출력
    }
    cout << endl;

    return 0;
}

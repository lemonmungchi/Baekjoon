#include <iostream>
#include <vector>
#include <string>

using namespace std;

// LPS (Longest Prefix Suffix) 배열 생성 함수
vector<int> computeLPSArray(const string& P) {
    int m = P.size();
    vector<int> lps(m, 0);
    int len = 0; // 길이가 일치하는 접두사와 접미사의 길이
    int i = 1;

    while (i < m) {
        if (P[i] == P[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// KMP 알고리즘을 이용한 패턴 검색
vector<int> KMPSearch(const string& T, const string& P) {
    int n = T.size();
    int m = P.size();
    vector<int> lps = computeLPSArray(P);
    vector<int> result;
    int i = 0; // 텍스트 T의 인덱스
    int j = 0; // 패턴 P의 인덱스

    while (i < n) {
        if (P[j] == T[i]) {
            i++;
            j++;
        }
        if (j == m) {
            result.push_back(i - j + 1); // 매칭 위치 저장 (1-based index)
            j = lps[j - 1];
        }
        else if (i < n && P[j] != T[i]) {
            if (j != 0) {
                j = lps[j - 1];
            }
            else {
                i++;
            }
        }
    }
    return result;
}

int main() {
    string T, P;
    getline(cin, T);
    getline(cin, P);

    vector<int> matches = KMPSearch(T, P);

    // 매칭 개수 출력
    cout << matches.size() << endl;

    // 매칭 위치 출력
    for (int pos : matches) {
        cout << pos << " ";
    }
    cout << endl;

    return 0;
}

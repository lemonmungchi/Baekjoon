#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ���̻� �迭 ���� �Լ�
vector<int> build_suffix_array(const string& s) {
    int n = s.size();
    vector<pair<string, int>> suffixes;  // ���̻�� �� ���̻簡 �����ϴ� �ε����� �����ϴ� ����

    // ��� ���̻縦 ����
    for (int i = 0; i < n; i++) {
        suffixes.push_back({ s.substr(i), i });
    }

    // ���̻縦 ���������� ����
    sort(suffixes.begin(), suffixes.end());

    // ���̻� �迭�� ���̻簡 ���۵Ǵ� �ε����� ����
    vector<int> suffix_array(n);
    for (int i = 0; i < n; i++) {
        suffix_array[i] = suffixes[i].second;
    }

    return suffix_array;
}

int main() {
    string s;
    cin >> s;

    // ���̻� �迭 ����
    vector<int> suffix_array = build_suffix_array(s);

    // ���̻� �迭 ���
    for (int i : suffix_array) {
        cout << i << " ";  // ���̻��� ���� �ε����� ���
    }
    cout << endl;

    return 0;
}

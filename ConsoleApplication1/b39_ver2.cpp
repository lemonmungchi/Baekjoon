#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    set<int> s1, s2;  // �� ������ ������ set

    // ���� A �Է�
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s1.insert(x);
    }

    // ���� B �Է�
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        s2.insert(x);
    }

    vector<int> diff1, diff2;  // �������� ������ ����

    // A - B ������
    set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(diff1));

    // B - A ������
    set_difference(s2.begin(), s2.end(), s1.begin(), s1.end(), back_inserter(diff2));

    // ��Ī �������� ���� ����
    cout << diff1.size() + diff2.size() << endl;

    return 0;
}

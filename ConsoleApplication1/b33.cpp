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

    // ��ǥ �Է¹ޱ�
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sorted_v.push_back(v[i]);
    }

    // �ߺ� ���� �� ����
    sort(sorted_v.begin(), sorted_v.end());
    sorted_v.erase(unique(sorted_v.begin(), sorted_v.end()), sorted_v.end());

    // ��ǥ ���� ����: �� ���� ����� �ε����� ����
    map<int, int> compression;
    for (int i = 0; i < sorted_v.size(); i++) {
        compression[sorted_v[i]] = i;
    }

    // ���� ��ǥ�� ���� ����� ��� ���
    for (int i = 0; i < n; i++) {
        cout << compression[v[i]] << " ";
    }

    return 0;
}

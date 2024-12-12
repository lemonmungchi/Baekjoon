#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n; // ���� ũ��
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end()); // ���� ����

    int target, cnt = 0;
    cin >> target; // ��ǥ ��

    int p = 0, q = n - 1; // �� ������ �ʱ�ȭ

    while (p < q) {
        int sum = v[p] + v[q];
        if (sum == target) { // ��ǥ �հ� ������
            cnt++;
            p++;    
            q--;    
        }
        else if (sum < target) {
            p++;    // ���� ������ ���� ���� ����
        }
        else {
            q--;    // ���� ũ�� ū ���� ����
        }
    }

    cout << cnt << endl; // ���� ���� ���

    return 0;
}

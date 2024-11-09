#include <iostream>
#include <vector>
#include <string>

using namespace std;

// LPS (Longest Prefix Suffix) �迭 ���� �Լ�
vector<int> computeLPSArray(const string& P) {
    int m = P.size();
    vector<int> lps(m, 0);
    int len = 0; // ���̰� ��ġ�ϴ� ���λ�� ���̻��� ����
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

// KMP �˰����� �̿��� ���� �˻�
vector<int> KMPSearch(const string& T, const string& P) {
    int n = T.size();
    int m = P.size();
    vector<int> lps = computeLPSArray(P);
    vector<int> result;
    int i = 0; // �ؽ�Ʈ T�� �ε���
    int j = 0; // ���� P�� �ε���

    while (i < n) {
        if (P[j] == T[i]) {
            i++;
            j++;
        }
        if (j == m) {
            result.push_back(i - j + 1); // ��Ī ��ġ ���� (1-based index)
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

    // ��Ī ���� ���
    cout << matches.size() << endl;

    // ��Ī ��ġ ���
    for (int pos : matches) {
        cout << pos << " ";
    }
    cout << endl;

    return 0;
}

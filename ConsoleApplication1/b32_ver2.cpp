#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ȸ�� ������ ��� ����ü
struct Member {
    int age;
    string name;
    int order;  // ���� ����
};

// ���� ���� �Լ�: ���̰� ������ ���� �������, �׷��� ������ ���� ��
bool cmp(const Member& a, const Member& b) {
    if (a.age == b.age) {
        return a.order < b.order;  // ���̰� ������ ���� ������� ����
    }
    return a.age < b.age;  // ���� ������ ����
}

int main() {
    int n;
    cin >> n;

    vector<Member> members;

    // ȸ�� ������ �Է¹ޱ�
    for (int i = 0; i < n; i++) {
        Member member;
        cin >> member.age >> member.name;
        member.order = i;  // ���� ������ ����
        members.push_back(member);
    }

    // ����: ���� �� -> ���̰� ������ ���� �������
    sort(members.begin(), members.end(), cmp);

    // ��� ���
    for (const Member& member : members) {
        cout << member.age << " " << member.name << '\n';
    }

    return 0;
}

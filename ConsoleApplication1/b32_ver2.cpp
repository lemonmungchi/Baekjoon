#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 회원 정보를 담는 구조체
struct Member {
    int age;
    string name;
    int order;  // 가입 순서
};

// 정렬 기준 함수: 나이가 같으면 가입 순서대로, 그렇지 않으면 나이 순
bool cmp(const Member& a, const Member& b) {
    if (a.age == b.age) {
        return a.order < b.order;  // 나이가 같으면 가입 순서대로 정렬
    }
    return a.age < b.age;  // 나이 순으로 정렬
}

int main() {
    int n;
    cin >> n;

    vector<Member> members;

    // 회원 정보를 입력받기
    for (int i = 0; i < n; i++) {
        Member member;
        cin >> member.age >> member.name;
        member.order = i;  // 가입 순서를 저장
        members.push_back(member);
    }

    // 정렬: 나이 순 -> 나이가 같으면 가입 순서대로
    sort(members.begin(), members.end(), cmp);

    // 결과 출력
    for (const Member& member : members) {
        cout << member.age << " " << member.name << '\n';
    }

    return 0;
}

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> vp;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first == p2.first) {
        return p1.second < p2.second;
    }
    return p1.first < p2.first;
}

int main() {
    int n;
    scanf("%d", &n);

    vp.reserve(n);

    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        vp.push_back({ x, y });
    }

    sort(vp.begin(), vp.end(), cmp);

    for (int i = 0; i < n; i++) {
        printf("%d %d\n", vp[i].first, vp[i].second);
    }

    return 0;
}

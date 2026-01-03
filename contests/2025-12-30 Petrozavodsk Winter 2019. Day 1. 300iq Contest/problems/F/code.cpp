#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, m;
int fa[N];
int get(int x) {
    if (x == fa[x])
        return x;
    return fa[x] = get(fa[x]);
}
bool merge(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y)
        return false;
    fa[x] = y;
    return true;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
    int cnt = n;
    for (int i = 1, x, y; i <= m; ++i) {
        scanf("%d%d", &x, &y);
        cnt -= merge(x, y);
    }
    printf("%d\n", m - (n - cnt));
}

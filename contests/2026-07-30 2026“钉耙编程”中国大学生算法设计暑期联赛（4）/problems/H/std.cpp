#include <bits/stdc++.h>
using namespace std;

#define ALL(s) s.begin(), s.end()
#define SZ(s) int(s.size())
#define pb push_back

using LL = long long;
using ULL = unsigned long long;

const int P = 998244353;

struct BIT {
  int n;
  vector<LL> t;
  BIT(int _n = 0) : n(_n), t(n + 1) {}
  void add(int p, LL v) {
    for (p++; p <= n; p += p & -p) t[p] += v;
  }
  LL qry(int p) const {
    LL ret = 0;
    for (; p; p -= p & -p) ret += t[p];
    return ret;
  }
  LL qry(int l, int r) const { return qry(r) - qry(l); }
};

struct RangeMax {
  int sz;
  vector<pair<int, int>> t;
  RangeMax(int n) : sz(1) {
    while (sz < n) sz *= 2;
    t.assign(2 * sz, {-1, -1});
  }
  void apply(int l, int r, pair<int, int> v) {
    for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
      if (l & 1) t[l] = max(t[l], v), l++;
      if (r & 1) --r, t[r] = max(t[r], v);
    }
  }
  int get(int p) const {
    pair<int, int> ret = {-1, -1};
    for (p += sz; p; p >>= 1) ret = max(ret, t[p]);
    return ret.second;
  }
};

ULL key(int l, int r) {
  return ULL(unsigned(l)) << 32 | unsigned(r);
}

void Main() {
  int n, m, K;
  cin >> n >> m >> K;
  vector<int> a(n + 1);
  vector<array<int, 5>> pre(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pre[i] = pre[i - 1];
    pre[i][a[i] - 1]++;
  }

  vector<pair<int, int>> q(m), seg;
  seg.reserve(m);
  for (auto &[l, r] : q) {
    cin >> l >> r;
    seg.pb({l, r});
  }
  sort(ALL(seg));
  seg.erase(unique(ALL(seg)), seg.end());
  sort(ALL(seg), [](auto x, auto y) {
    if (x.first != y.first) return x.first < y.first;
    return x.second > y.second;
  });

  int N = SZ(seg) + 1;
  vector<int> L(N), R(N), fa(N, -1), dep(N), len(N);
  vector<vector<int>> e(N);
  L[0] = 1, R[0] = n, len[0] = n;
  unordered_map<ULL, int> id;
  id.reserve(2 * N);
  for (int i = 1; i < N; i++) {
    tie(L[i], R[i]) = seg[i - 1];
    len[i] = R[i] - L[i] + 1;
    id[key(L[i], R[i])] = i;
  }

  vector<int> stk = {0};
  for (int v = 1; v < N; v++) {
    while (SZ(stk) > 1 && R[stk.back()] < R[v]) stk.pop_back();
    fa[v] = stk.back();
    dep[v] = dep[fa[v]] + 1;
    e[fa[v]].pb(v);
    stk.pb(v);
  }
  vector<int> op(m);
  for (int i = 0; i < m; i++) op[i] = id[key(q[i].first, q[i].second)];

  vector<int> tin(N), tout(N), ord;
  ord.reserve(N);
  vector<pair<int, int>> dfs = {{0, 0}};
  int tim = 0;
  while (!dfs.empty()) {
    int v = dfs.back().first;
    int &i = dfs.back().second;
    if (i == 0) tin[v] = tim++, ord.pb(v);
    if (i < SZ(e[v])) {
      int u = e[v][i++];
      dfs.pb({u, 0});
    } else {
      tout[v] = tim;
      dfs.pop_back();
    }
  }

  vector<array<int, 5>> init(N);
  vector<int> gapMask(N);
  int all = (1 << K) - 1;
  for (int v = 0; v < N; v++) {
    for (int c = 0; c < K; c++) {
      init[v][c] = pre[R[v]][c] - pre[L[v] - 1][c];
    }
  }
  for (int v = 0; v < N; v++) {
    int gapLen = len[v];
    array<int, 5> gap = init[v];
    for (int u : e[v]) {
      gapLen -= len[u];
      for (int c = 0; c < K; c++) gap[c] -= init[u][c];
    }
    if (!gapLen) {
      gapMask[v] = all;
    } else {
      for (int c = 0; c < K; c++) {
        if (gap[c] == gapLen) gapMask[v] |= 1 << c;
      }
    }
  }

  vector<int> good(N);
  for (int c = 0; c < K; c++) {
    BIT bit(N);
    RangeMax anc(N);
    vector<char> active(N);
    for (int v : op) {
      if (active[v]) continue;
      LL cur = init[v][c] + bit.qry(tin[v], tout[v]);
      if (2 * cur <= len[v]) continue;
      int r = anc.get(tin[v]);
      LL delta = len[v] - cur;
      bit.add(tin[v], delta);
      if (r != -1) bit.add(tin[r], -delta);
      anc.apply(tin[v], tout[v], {dep[v], v});
      active[v] = 1;
      good[v] |= 1 << c;
    }
  }

  vector<int> ways(N), uni(N);
  reverse(ALL(ord));
  for (int v : ord) {
    int base = 1, mask = gapMask[v];
    for (int u : e[v]) {
      base = int(LL(base) * ways[u] % P);
      mask &= uni[u];
    }
    ways[v] = base + __builtin_popcount(good[v] & ~mask & all);
    if (ways[v] >= P) ways[v] -= P;
    uni[v] = mask | good[v];
  }
  cout << ways[0] << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T = 1;
  cin >> T;
  while (T--) Main();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define pb push_back

const int LG = 20;
const int INF = 1e9;

struct Fn {
  int a, b;
};

Fn merge(Fn f, Fn g) {
  return {max(f.a, g.a + f.b), f.b + g.b};
}

int calc(Fn f, int x) {
  return max(f.a, x + f.b);
}

void Main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1), lc(n + 1), rc(n + 1), fa(n + 1);
  vector<int> stk;
  stk.reserve(n);

  rep(i, 1, n) {
    cin >> a[i];
    int las = 0;
    while (!stk.empty() && a[stk.back()] > a[i]) {
      las = stk.back();
      stk.pop_back();
    }
    if (!stk.empty()) {
      rc[stk.back()] = i;
      fa[i] = stk.back();
    }
    if (las) {
      lc[i] = las;
      fa[las] = i;
    }
    stk.pb(i);
  }
  int rt = stk[0];

  vector<int> dep(n + 1), h(n + 1), ord;
  ord.reserve(n);
  stk = {rt};
  while (!stk.empty()) {
    int u = stk.back();
    stk.pop_back();
    ord.pb(u);
    if (lc[u]) {
      dep[lc[u]] = dep[u] + 1;
      stk.pb(lc[u]);
    }
    if (rc[u]) {
      dep[rc[u]] = dep[u] + 1;
      stk.pb(rc[u]);
    }
  }
  reverse(ord.begin(), ord.end());
  for (int u : ord) h[u] = 1 + max(h[lc[u]], h[rc[u]]);

  const Fn I = {-INF, 0};
  array<vector<int>, LG> up;
  array<vector<Fn>, LG> pre, suf;
  rep(j, 0, LG - 1) {
    up[j].resize(n + 1);
    pre[j].assign(n + 1, I);
    suf[j].assign(n + 1, I);
  }

  rep(u, 1, n) {
    if (u == rt) {
      up[0][u] = u;
      continue;
    }
    int p = fa[u];
    up[0][u] = p;
    if (rc[p] == u) pre[0][u] = {1 + h[lc[p]], 1};
    if (lc[p] == u) suf[0][u] = {1 + h[rc[p]], 1};
  }
  rep(j, 1, LG - 1) {
    rep(u, 1, n) {
      int p = up[j - 1][u];
      up[j][u] = up[j - 1][p];
      pre[j][u] = merge(pre[j - 1][p], pre[j - 1][u]);
      suf[j][u] = merge(suf[j - 1][p], suf[j - 1][u]);
    }
  }

  auto lca = [&](int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    int d = dep[u] - dep[v];
    rep(j, 0, LG - 1) {
      if (d >> j & 1) u = up[j][u];
    }
    if (u == v) return u;
    for (int j = LG - 1; j >= 0; j--) {
      if (up[j][u] != up[j][v]) {
        u = up[j][u];
        v = up[j][v];
      }
    }
    return fa[u];
  };

  auto path = [&](int u, int v, const auto& f) {
    Fn ret = I;
    int d = dep[v] - dep[u];
    rep(j, 0, LG - 1) {
      if (d >> j & 1) {
        ret = merge(f[j][v], ret);
        v = up[j][v];
      }
    }
    return ret;
  };

  auto pref = [&](int u, int v) {
    return calc(path(u, v, pre), 1 + h[lc[v]]);
  };
  auto suff = [&](int u, int v) {
    return calc(path(u, v, suf), 1 + h[rc[v]]);
  };

  while (q--) {
    int l, r;
    cin >> l >> r;
    int m = lca(l, r);
    int L = l < m ? suff(lc[m], l) : 0;
    int R = m < r ? pref(rc[m], r) : 0;
    cout << 1 + max(L, R) << "\n";
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T;
  cin >> T;
  while (T--) Main();
  return 0;
}

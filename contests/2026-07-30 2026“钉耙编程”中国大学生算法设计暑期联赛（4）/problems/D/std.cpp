#include <bits/stdc++.h>
using namespace std;

#define SZ(s) int(s.size())
#define pb push_back

using LL = long long;

const int INF = 1e9;

struct DP {
  int f[2][5];
};

void clear(DP& a) {
  for (auto& r : a.f) fill(r, r + 5, INF);
}

void Main() {
  int n;
  LL k, x, y;
  cin >> n >> k >> x >> y;
  vector<LL> a(n + 1);
  vector<int> b(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = int(min<LL>(a[i] - 1, 2));
  }

  vector<vector<int>> g(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }

  if (n == 1) {
    LL ans = -1;
    if (k == 1 && a[1] >= 2) ans = x;
    if (k == 2 && a[1] >= 3) ans = x;
    cout << ans << "\n";
    return;
  }

  auto bfs = [&](int s, vector<int>& d, vector<int>* p = nullptr) {
    d.assign(n + 1, -1);
    if (p) p->assign(n + 1, 0);
    vector<int> q(n);
    int l = 0, r = 0;
    q[r++] = s;
    d[s] = 0;
    while (l < r) {
      int u = q[l++];
      for (int v : g[u]) {
        if (d[v] != -1) continue;
        d[v] = d[u] + 1;
        if (p) (*p)[v] = u;
        q[r++] = v;
      }
    }
  };

  auto far = [&](const vector<int>& d) {
    return int(max_element(d.begin() + 1, d.end()) - d.begin());
  };

  vector<int> d, ds, dt, par;
  bfs(1, d);
  int S = far(d);
  bfs(S, ds, &par);
  int T = far(ds), D = ds[T];
  bfs(T, dt);

  if (k <= D) {
    cout << 0 << "\n";
    return;
  }
  if (k > D + 2) {
    cout << -1 << "\n";
    return;
  }

  if (k == D + 1) {
    vector<int> dis(n + 1, -1), q(n);
    int l = 0, r = 0;
    for (int u = 1; u <= n; u++) {
      if (a[u] > 1) {
        dis[u] = 0;
        q[r++] = u;
      }
    }
    if (!r) {
      cout << -1 << "\n";
      return;
    }
    while (l < r) {
      int u = q[l++];
      for (int v : g[u]) {
        if (dis[v] != -1) continue;
        dis[v] = dis[u] + 1;
        q[r++] = v;
      }
    }
    int mn = INF;
    for (int u = 1; u <= n; u++) {
      if (max(ds[u], dt[u]) == D) mn = min(mn, dis[u]);
    }
    cout << x + LL(mn) * y << "\n";
    return;
  }

  int sum = 0;
  for (int u = 1; u <= n; u++) sum = min(2, sum + b[u]);
  if (sum < 2) {
    cout << -1 << "\n";
    return;
  }

  vector<int> path;
  for (int u = T; u; u = par[u]) path.pb(u);
  reverse(path.begin(), path.end());

  vector<int> fa(n + 1), dep(n + 1), ord;
  vector<DP> f(n + 1);
  ord.reserve(n);

  auto run = [&](int rt, int ban, int R) {
    ord.clear();
    ord.pb(rt);
    fa[rt] = ban;
    dep[rt] = 0;
    for (int i = 0; i < SZ(ord); i++) {
      int u = ord[i];
      for (int v : g[u]) {
        if (v == fa[u]) continue;
        fa[v] = u;
        dep[v] = dep[u] + 1;
        ord.pb(v);
      }
    }

    for (int z = SZ(ord) - 1; z >= 0; z--) {
      int u = ord[z];
      DP cur;
      clear(cur);
      int can = dep[u] == R;
      for (int t = 0; t <= can; t++) {
        for (int r = 0; r <= b[u]; r++) {
          cur.f[t][t - r + 2] = 0;
        }
      }

      for (int v : g[u]) {
        if (v == fa[u]) continue;
        DP nxt;
        clear(nxt);
        for (int t = 0; t <= 1; t++) {
          for (int qi = 0; qi < 5; qi++) {
            if (cur.f[t][qi] == INF) continue;
            int q = qi - 2;
            for (int s = 0; t + s <= 1; s++) {
              for (int ri = 0; ri < 5; ri++) {
                if (f[v].f[s][ri] == INF) continue;
                int r = ri - 2;
                if (abs(q + r) > 2) continue;
                int& w = nxt.f[t + s][q + r + 2];
                w = min(w, cur.f[t][qi] + f[v].f[s][ri] + (r != 0));
              }
            }
          }
        }
        cur = nxt;
      }
      f[u] = cur;
    }
  };

  int R = D / 2, m = INF;
  if (D % 2 == 0) {
    int c = path[R];
    run(c, 0, R);

    int h[3][5], nh[3][5];
    for (auto& r : h) fill(r, r + 5, INF);
    for (int r = 0; r <= b[c]; r++) h[0][-r + 2] = 0;

    for (int v : g[c]) {
      for (auto& r : nh) fill(r, r + 5, INF);
      for (int t = 0; t <= 2; t++) {
        for (int qi = 0; qi < 5; qi++) {
          if (h[t][qi] == INF) continue;
          int q = qi - 2;
          for (int s = 0; s <= 1 && t + s <= 2; s++) {
            for (int ri = 0; ri < 5; ri++) {
              if (f[v].f[s][ri] == INF) continue;
              int r = ri - 2;
              if (abs(q + r) > 2) continue;
              int& w = nh[t + s][q + r + 2];
              w = min(w, h[t][qi] + f[v].f[s][ri] + (r != 0));
            }
          }
        }
      }
      memcpy(h, nh, sizeof h);
    }
    m = h[2][2];
  } else {
    int cl = path[R], cr = path[R + 1];
    run(cl, cr, R);
    DP L = f[cl];
    run(cr, cl, R);
    DP Rf = f[cr];
    for (int q = -2; q <= 2; q++) {
      int l = L.f[1][q + 2], r = Rf.f[1][-q + 2];
      if (l == INF || r == INF) continue;
      m = min(m, l + r + (q != 0));
    }
  }

  if (m == INF) cout << -1 << "\n";
  else cout << 2 * x + LL(m) * y << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) Main();
  return 0;
}

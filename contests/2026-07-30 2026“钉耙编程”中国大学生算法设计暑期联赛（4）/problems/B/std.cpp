#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i <= (b); i++)

using LL = long long;

struct DSU {
  vector<int> f, s;

  DSU(int n) : f(n), s(n, 1) {
    iota(f.begin(), f.end(), 0);
  }

  int find(int u) {
    while (u != f[u]) {
      f[u] = f[f[u]];
      u = f[u];
    }
    return u;
  }

  bool merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return 0;
    if (s[u] < s[v]) swap(u, v);
    f[v] = u;
    s[u] += s[v];
    return 1;
  }
};

void Main() {
  int n;
  cin >> n;
  vector<LL> a(n), b(n), c(n), val;
  val.reserve(2 * n);
  rep(i, 0, n - 1) {
    cin >> a[i] >> b[i] >> c[i];
    val.push_back(a[i]);
    val.push_back(b[i]);
  }
  sort(val.begin(), val.end());
  val.erase(unique(val.begin(), val.end()), val.end());

  int m = val.size();
  vector<int> u(n), v(n);
  rep(i, 0, n - 1) {
    u[i] = lower_bound(val.begin(), val.end(), a[i]) - val.begin();
    v[i] = lower_bound(val.begin(), val.end(), b[i]) - val.begin();
  }

  DSU dsu(m);
  vector<char> tr(n, 0);
  vector<vector<pair<int, int>>> g(m);
  rep(i, 0, n - 1) {
    if (dsu.merge(u[i], v[i])) {
      tr[i] = 1;
      g[u[i]].push_back({v[i], i});
      g[v[i]].push_back({u[i], i});
    }
  }

  vector<int> cnt(m, 0);
  rep(i, 0, n - 1) cnt[dsu.find(u[i])]++;
  bool ok = 1;
  rep(i, 0, m - 1) {
    if (dsu.find(i) == i && cnt[i] % 2) ok = 0;
  }

  vector<int> pick(n, -1), odd(m, 0);
  rep(i, 0, n - 1) {
    if (!tr[i]) {
      pick[i] = 0;
      odd[u[i]] ^= 1;
    }
  }

  vector<int> par(m, -2), pe(m, -1), ord;
  ord.reserve(m);
  rep(rt, 0, m - 1) {
    if (par[rt] != -2) continue;
    par[rt] = -1;
    vector<int> stk = {rt};
    while (!stk.empty()) {
      int x = stk.back();
      stk.pop_back();
      ord.push_back(x);
      for (auto [y, id] : g[x]) {
        if (y == par[x]) continue;
        par[y] = x;
        pe[y] = id;
        stk.push_back(y);
      }
    }
  }

  for (int i = (int)ord.size() - 1; i >= 0; i--) {
    int x = ord[i];
    if (par[x] == -1) continue;
    int id = pe[x];
    int to = odd[x] ? x : par[x];
    pick[id] = (v[id] == to);
    odd[to] ^= 1;
  }
  rep(i, 0, m - 1) {
    if (odd[i]) ok = 0;
  }

  vector<int> cm(n, -1), vm(n, -1), id(n);
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&](int x, int y) {
    if (c[x] != c[y]) return c[x] < c[y];
    return x < y;
  });
  for (int l = 0, r; l < n; l = r) {
    for (r = l + 1; r < n && c[id[r]] == c[id[l]]; r++);
    if ((r - l) % 2) ok = 0;
    for (int i = l; i + 1 < r; i += 2) {
      cm[id[i]] = id[i + 1];
      cm[id[i + 1]] = id[i];
    }
  }

  vector<int> sel(n);
  rep(i, 0, n - 1) {
    sel[i] = pick[i] ? v[i] : u[i];
  }
  sort(id.begin(), id.end(), [&](int x, int y) {
    if (sel[x] != sel[y]) return sel[x] < sel[y];
    return x < y;
  });
  for (int l = 0, r; l < n; l = r) {
    for (r = l + 1; r < n && sel[id[r]] == sel[id[l]]; r++);
    if ((r - l) % 2) ok = 0;
    for (int i = l; i + 1 < r; i += 2) {
      vm[id[i]] = id[i + 1];
      vm[id[i + 1]] = id[i];
    }
  }

  if (!ok) {
    cout << -1 << "\n";
    return;
  }

  vector<int> col(n, -1);
  rep(s, 0, n - 1) {
    if (col[s] != -1) continue;
    col[s] = 0;
    vector<int> stk = {s};
    while (!stk.empty()) {
      int x = stk.back();
      stk.pop_back();
      for (int y : {cm[x], vm[x]}) {
        if (col[y] == -1) {
          col[y] = col[x] ^ 1;
          stk.push_back(y);
        } else if (col[y] == col[x]) {
          ok = 0;
        }
      }
    }
  }

  if (!ok) {
    cout << -1 << "\n";
    return;
  }
  rep(i, 0, n - 1) cout << pick[i];
  cout << "\n";
  rep(i, 0, n - 1) cout << col[i];
  cout << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) Main();
  return 0;
}

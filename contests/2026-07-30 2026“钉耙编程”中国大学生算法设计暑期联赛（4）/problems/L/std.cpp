#include <bits/stdc++.h>
using namespace std;

#define ALL(s) s.begin(), s.end()
#define SZ(s) int(s.size())
#define pb push_back

struct SuffixArray {
  int n;
  vector<int> sa, rk, lc;
  SuffixArray(const string& s) : n(SZ(s)), sa(n), rk(n), lc(n - 1) {
    iota(ALL(sa), 0);
    sort(ALL(sa), [&](int x, int y) { return s[x] < s[y]; });
    rk[sa[0]] = 0;
    for (int i = 1; i < n; i++) {
      rk[sa[i]] = rk[sa[i - 1]] + (s[sa[i]] != s[sa[i - 1]]);
    }
    vector<int> tmp, cnt(n);
    tmp.reserve(n);
    for (int w = 1; rk[sa[n - 1]] < n - 1; w *= 2) {
      tmp.clear();
      for (int i = n - w; i < n; i++) tmp.pb(i);
      for (int i = 0; i < n; i++) if (sa[i] >= w) tmp.pb(sa[i] - w);
      fill(ALL(cnt), 0);
      for (int i = 0; i < n; i++) cnt[rk[i]]++;
      partial_sum(ALL(cnt), cnt.begin());
      for (int i = n - 1; i >= 0; i--) sa[--cnt[rk[tmp[i]]]] = tmp[i];
      swap(rk, tmp);
      rk[sa[0]] = 0;
      for (int i = 1; i < n; i++) {
        rk[sa[i]] = rk[sa[i - 1]]
          + (tmp[sa[i]] != tmp[sa[i - 1]] || sa[i - 1] + w == n
             || tmp[sa[i] + w] != tmp[sa[i - 1] + w]);
      }
    }
    for (int i = 0, k = 0; i < n; i++) {
      int j = rk[i];
      if (!j) continue;
      if (k) k--;
      while (i + k < n && sa[j - 1] + k < n
             && s[i + k] == s[sa[j - 1] + k]) k++;
      lc[j - 1] = k;
    }
  }
};

struct RMQ {
  vector<vector<int>> st;
  RMQ(const vector<int>& a) : st(__lg(SZ(a)) + 1) {
    st[0] = a;
    for (int d = 1; d < SZ(st); d++) {
      int n = SZ(a) - (1 << d) + 1;
      st[d].resize(n);
      for (int i = 0; i < n; i++) {
        st[d][i] = min(st[d - 1][i], st[d - 1][i + (1 << (d - 1))]);
      }
    }
  }
  int qry(int l, int r) const {
    int d = __lg(r - l);
    return min(st[d][l], st[d][r - (1 << d)]);
  }
};

struct PartitionTree {
  int h;
  vector<int> V, mid;
  vector<vector<int>> pre;
  PartitionTree(vector<int> a) : V(a) {
    sort(ALL(V));
    V.erase(unique(ALL(V)), V.end());
    for (int& x : a) x = int(lower_bound(ALL(V), x) - V.begin());
    h = 32 - __builtin_clz(max(1, SZ(V) - 1));
    pre.assign(h, vector<int>(SZ(a) + 1));
    mid.resize(h);
    vector<int> b(SZ(a));
    for (int d = 0; d < h; d++) {
      int w = h - d - 1;
      for (int i = 0; i < SZ(a); i++) {
        pre[d][i + 1] = pre[d][i] + !(a[i] >> w & 1);
      }
      int x = 0, y = mid[d] = pre[d].back();
      for (int v : a) b[v >> w & 1 ? y++ : x++] = v;
      swap(a, b);
    }
  }
  int less(int l, int r, int v) const {
    int k = int(lower_bound(ALL(V), v) - V.begin());
    if (!k) return 0;
    if (k == SZ(V)) return r - l;
    int ret = 0;
    for (int d = 0; d < h; d++) {
      int ql = pre[d][l], qr = pre[d][r], cnt = qr - ql;
      if (k >> (h - d - 1) & 1) {
        ret += cnt;
        l += mid[d] - ql, r += mid[d] - qr;
      } else {
        l = ql, r = qr;
      }
    }
    return ret;
  }
  int kth(int l, int r, int k) const {
    assert(0 <= l && l <= r && 0 <= k && k < r - l);
    int x = 0;
    for (int d = 0; d < h; d++) {
      int ql = pre[d][l], qr = pre[d][r], cnt = qr - ql;
      if (k < cnt) {
        l = ql, r = qr;
      } else {
        k -= cnt, x |= 1 << (h - d - 1);
        l += mid[d] - ql, r += mid[d] - qr;
      }
    }
    return V[x];
  }
};

struct DSU {
  vector<int> f;
  vector<set<int>> s;
  vector<vector<pair<int, int>>>& e;

  DSU(const vector<int>& sa, vector<vector<pair<int, int>>>& _e)
      : f(SZ(sa)), s(SZ(sa)), e(_e) {
    iota(ALL(f), 0);
    for (int i = 0; i < SZ(sa); i++) s[i].insert(sa[i]);
  }
  int find(int u) {
    while (u != f[u]) u = f[u] = f[f[u]];
    return u;
  }
  void add(int p, int q, int d) {
    int x = min(p, q), y = max(p, q);
    e[x].pb({y, d});
  }
  void merge(int u, int v, int d) {
    u = find(u), v = find(v);
    if (s[u].size() > s[v].size()) swap(u, v);
    for (int p : s[u]) {
      auto it = s[v].lower_bound(p);
      if (it != s[v].end()) add(p, *it, d);
      if (it != s[v].begin()) add(p, *prev(it), d);
    }
    s[v].merge(s[u]);
    f[u] = v;
  }
};

struct MaxInfo {
  int v = -1, w = INT_MAX, x = -1, y = -1;
  MaxInfo& operator+=(const MaxInfo& o) {
    if (v < o.v || (v == o.v && tie(o.w, o.x, o.y) < tie(w, x, y))) {
      *this = o;
    }
    return *this;
  }
};

struct MinInfo {
  int v = INT_MAX, w = INT_MAX, x = -1, y = -1;
  MinInfo& operator+=(const MinInfo& o) {
    if (tie(o.v, o.w, o.x, o.y) < tie(v, w, x, y)) *this = o;
    return *this;
  }
};

template <class T>
struct BIT {
  int n;
  vector<T> a;
  BIT(int _n = 0) : n(_n), a(_n + 1) {}
  void mdf(int p, const T& v) {
    for (int i = p + 1; i <= n; i += i & -i) a[i] += v;
  }
  T qry(int p) const {
    T r{};
    for (int i = p; i > 0; i -= i & -i) r += a[i];
    return r;
  }
};

void Main() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<int> ql(m), qr(m);
  vector<vector<pair<int, int>>> qs(n);
  for (int i = 0; i < m; i++) {
    cin >> ql[i] >> qr[i];
    ql[i]--;
    qs[ql[i]].pb({qr[i], i});
  }

  SuffixArray sa(s);
  vector<vector<pair<int, int>>> e(n);
  {
    vector<pair<int, int>> ed;
    ed.reserve(n - 1);
    for (int i = 0; i < n - 1; i++) ed.pb({sa.lc[i], i});
    sort(ed.rbegin(), ed.rend());
    DSU dsu(sa.sa, e);
    for (auto [d, i] : ed) {
      if (!d) break;
      dsu.merge(i, i + 1, d);
    }
  }

  vector<int> ans_h(m), win(m);
  {
    BIT<MaxInfo> bit0(n);
    BIT<MinInfo> bit1(n);
    for (int l = n - 1; l >= 0; l--) {
      for (auto [y, d] : e[l]) {
        int z = y + d;
        int w = min(sa.rk[l], sa.rk[y]);
        bit0.mdf(z - 1, {d, w, l, y});
        bit1.mdf(n - z, {y, w, l, y});
      }
      for (auto [r, id] : qs[l]) {
        MaxInfo a = bit0.qry(r);
        MinInfo b = bit1.qry(n - r);
        int h = a.v, w = a.w, p = a.x;
        int cur = b.v < r ? r - b.v : -1;
        if (h < cur || (h == cur && b.w < w)) {
          h = cur, w = b.w, p = b.x;
        }
        assert(h > 0 && p >= 0);
        ans_h[id] = h, win[id] = p;
      }
    }
  }
  vector<vector<pair<int, int>>>().swap(e);
  vector<vector<pair<int, int>>>().swap(qs);

  RMQ rmq(sa.lc);
  PartitionTree pt(sa.rk);
  vector<array<int, 3>> ans(m);
  for (int id = 0; id < m; id++) {
    int h = ans_h[id], p = sa.rk[win[id]];
    int l = 0, r = p;
    while (l < r) {
      int mid = (l + r) / 2;
      if (rmq.qry(mid, p) >= h) r = mid;
      else l = mid + 1;
    }
    int A = l;
    l = p, r = n - 1;
    while (l < r) {
      int mid = (l + r + 1) / 2;
      if (rmq.qry(p, mid) >= h) l = mid;
      else r = mid - 1;
    }
    int B = l;

    int R = qr[id] - h;
    int x, y;
    if (A <= sa.rk[R] && sa.rk[R] <= B) {
      x = R;
      int k = pt.less(ql[id], R, A);
      int v = pt.kth(ql[id], R, k);
      assert(v <= B);
      y = sa.sa[v];
    } else {
      int k = pt.less(ql[id], R + 1, A);
      int u = pt.kth(ql[id], R + 1, k);
      int v = pt.kth(ql[id], R + 1, k + 1);
      assert(u <= B && v <= B);
      x = sa.sa[u], y = sa.sa[v];
    }
    ans[id] = {h, x + 1, y + 1};
  }
  for (auto [h, x, y] : ans) cout << h << " " << x << " " << y << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  cin >> t;
  while (t--) Main();
  return 0;
}
